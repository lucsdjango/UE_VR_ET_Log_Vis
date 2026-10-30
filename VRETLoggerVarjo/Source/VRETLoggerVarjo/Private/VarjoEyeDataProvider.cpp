// Fill out your copyright notice in the Description page of Project Settings.

#include "VarjoEyeDataProvider.h"

#if WITH_VARJO_SDK

#include "Engine/Engine.h"
#include "HAL/IConsoleManager.h"
#include "HAL/PlatformTime.h"
#include "IXRTrackingSystem.h"

THIRD_PARTY_INCLUDES_START
#include "Varjo.h"
THIRD_PARTY_INCLUDES_END

static TAutoConsoleVariable<float> CVarBlinkOpennessThreshold(
	TEXT("vret.Varjo.BlinkOpennessThreshold"),
	0.2f,
	TEXT("Eye openness (0 = closed, 1 = open) below which an eye is logged as blinking. Varjo marks openness as experimental."));

// Varjo gaze rays are left-handed (X right, Y up, Z forward), in metres and relative to the head pose.
static FVector VarjoToUnreal(const double Vector[3])
{
	return FVector(Vector[2], Vector[0], Vector[1]);
}

FVarjoEyeDataProvider::~FVarjoEyeDataProvider()
{
	if (Session)
	{
		varjo_SessionShutDown(Session);
	}
}

void FVarjoEyeDataProvider::StartTracking()
{
	LastStartAttemptTime = FPlatformTime::Seconds();
	if (bGazeInitialized)
	{
		return;
	}

	if (!Session)
	{
		Session = varjo_SessionInit();
		if (!Session)
		{
			UE_LOG(LogTemp, Warning, TEXT("VRETLoggerVarjo: could not connect to the Varjo runtime, is Varjo Base running?"));
			return;
		}
	}

	if (!varjo_IsGazeAllowed(Session))
	{
		UE_LOG(LogTemp, Warning, TEXT("VRETLoggerVarjo: eye tracking is not allowed, enable 'Allow eye tracking' in Varjo Base."));
		return;
	}

	varjo_GazeInit(Session);
	const varjo_Error Error = varjo_GetError(Session);
	if (Error != varjo_NoError && Error != varjo_Error_GazeAlreadyInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("VRETLoggerVarjo: gaze tracking failed to start: %s"), ANSI_TO_TCHAR(varjo_GetErrorDesc(Error)));
		return;
	}

	bGazeInitialized = true;
	UE_LOG(LogTemp, Log, TEXT("VRETLoggerVarjo: gaze tracking started."));
}

bool FVarjoEyeDataProvider::GetEyeData(FVRETEyeData& OutData)
{
	// The runtime or headset may not be ready when logging starts, so retry (at most once per second) until it is.
	if (!bGazeInitialized && FPlatformTime::Seconds() - LastStartAttemptTime > 1.0)
	{
		StartTracking();
	}
	if (!bGazeInitialized || !GEngine || !GEngine->XRSystem.IsValid())
	{
		return false;
	}

	varjo_Gaze Gaze;
	varjo_EyeMeasurements Measurements;
	if (!varjo_GetGazeData(Session, &Gaze, &Measurements))
	{
		return false;
	}

	// Gaze is relative to the head. Use the engine's HMD pose for this frame, so the rays match the logged HeadPos.
	FQuat HeadOrientation;
	FVector HeadPosition;
	if (!GEngine->XRSystem->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, HeadOrientation, HeadPosition))
	{
		return false;
	}
	const float WorldToMeters = GEngine->XRSystem->GetWorldToMetersScale();
	const FTransform HeadToWorld = FTransform(HeadOrientation, HeadPosition) * GEngine->XRSystem->GetTrackingToWorldTransform();

	auto RayToWorld = [&HeadToWorld, WorldToMeters](const varjo_Ray& Ray, FVector& OutOrigin, FVector& OutDirection)
	{
		OutOrigin = HeadToWorld.TransformPosition(VarjoToUnreal(Ray.origin) * WorldToMeters);
		OutDirection = HeadToWorld.TransformVectorNoScale(VarjoToUnreal(Ray.forward)).GetSafeNormal();
	};

	OutData.bLeftEyeValid = Gaze.leftStatus >= varjo_GazeEyeStatus_Compensated;
	if (OutData.bLeftEyeValid)
	{
		RayToWorld(Gaze.leftEye, OutData.LeftOrigin, OutData.LeftDirection);
	}
	OutData.bRightEyeValid = Gaze.rightStatus >= varjo_GazeEyeStatus_Compensated;
	if (OutData.bRightEyeValid)
	{
		RayToWorld(Gaze.rightEye, OutData.RightOrigin, OutData.RightDirection);
	}

	// Varjo's own depth estimate (0-2 m) along the combined gaze ray.
	if (Gaze.status == varjo_GazeStatus_Valid && Gaze.focusDistance > 0.0)
	{
		FVector GazeOrigin, GazeDirection;
		RayToWorld(Gaze.gaze, GazeOrigin, GazeDirection);
		OutData.bFixationPointValid = true;
		OutData.FixationPoint = GazeOrigin + GazeDirection * (Gaze.focusDistance * WorldToMeters);
	}

	const float OpennessThreshold = CVarBlinkOpennessThreshold.GetValueOnGameThread();
	OutData.bBlinkValid = true;
	OutData.bLeftBlink = Gaze.leftStatus == varjo_GazeEyeStatus_Invalid || Measurements.leftEyeOpenness < OpennessThreshold;
	OutData.bRightBlink = Gaze.rightStatus == varjo_GazeEyeStatus_Invalid || Measurements.rightEyeOpenness < OpennessThreshold;

	// 0 when the pupil is not tracked.
	OutData.bPupilValid = true;
	OutData.LeftPupilDiameter = Measurements.leftPupilDiameterInMM;
	OutData.RightPupilDiameter = Measurements.rightPupilDiameterInMM;

	return true;
}

#endif // WITH_VARJO_SDK
