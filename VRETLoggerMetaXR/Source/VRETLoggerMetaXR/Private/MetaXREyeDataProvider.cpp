// Fill out your copyright notice in the Description page of Project Settings.

#include "MetaXREyeDataProvider.h"

#include "Engine/Engine.h"
#include "HAL/IConsoleManager.h"
#include "HAL/PlatformTime.h"
#include "IXRTrackingSystem.h"
#include "OculusXRMovementFunctionLibrary.h"

static TAutoConsoleVariable<float> CVarBlinkThreshold(
	TEXT("vret.MetaXR.BlinkThreshold"),
	0.5f,
	TEXT("EyesClosed face expression weight (0-1) above which an eye is logged as blinking."));

void FMetaXREyeDataProvider::StartTracking()
{
	LastStartAttemptTime = FPlatformTime::Seconds();

	if (UOculusXRMovementFunctionLibrary::IsEyeTrackingSupported() && !UOculusXRMovementFunctionLibrary::IsEyeTrackingEnabled())
	{
		UOculusXRMovementFunctionLibrary::StartEyeTracking();
	}
	if (UOculusXRMovementFunctionLibrary::IsFaceTrackingSupported() && !UOculusXRMovementFunctionLibrary::IsFaceTrackingEnabled())
	{
		UOculusXRMovementFunctionLibrary::StartFaceTracking();
	}
}

bool FMetaXREyeDataProvider::GetEyeData(FVRETEyeData& OutData)
{
	if (!GEngine || !GEngine->XRSystem.IsValid())
	{
		return false;
	}

	// Tracking can only be started once the XR session is running, so retry (at most once per second) until it is.
	const bool bEyeNeedsStart = UOculusXRMovementFunctionLibrary::IsEyeTrackingSupported() && !UOculusXRMovementFunctionLibrary::IsEyeTrackingEnabled();
	const bool bFaceNeedsStart = UOculusXRMovementFunctionLibrary::IsFaceTrackingSupported() && !UOculusXRMovementFunctionLibrary::IsFaceTrackingEnabled();
	if ((bEyeNeedsStart || bFaceNeedsStart) && FPlatformTime::Seconds() - LastStartAttemptTime > 1.0)
	{
		StartTracking();
	}

	// Eye poses are in tracking space, convert to world space like Unreal's OpenXR eye tracker does for the combined gaze.
	const FTransform TrackingToWorld = GEngine->XRSystem->GetTrackingToWorldTransform();

	FOculusXREyeGazesState GazesState;
	if (UOculusXRMovementFunctionLibrary::TryGetEyeGazesState(GazesState) && GazesState.EyeGazes.Num() >= static_cast<int32>(EOculusXREye::COUNT))
	{
		const FOculusXREyeGazeState& Left = GazesState.EyeGazes[static_cast<int32>(EOculusXREye::Left)];
		const FOculusXREyeGazeState& Right = GazesState.EyeGazes[static_cast<int32>(EOculusXREye::Right)];

		if (Left.bIsValid)
		{
			const FTransform EyeTransform = FTransform(Left.Orientation, Left.Position) * TrackingToWorld;
			OutData.bLeftEyeValid = true;
			OutData.LeftOrigin = EyeTransform.GetLocation();
			OutData.LeftDirection = EyeTransform.GetRotation().GetForwardVector();
		}
		if (Right.bIsValid)
		{
			const FTransform EyeTransform = FTransform(Right.Orientation, Right.Position) * TrackingToWorld;
			OutData.bRightEyeValid = true;
			OutData.RightOrigin = EyeTransform.GetLocation();
			OutData.RightDirection = EyeTransform.GetRotation().GetForwardVector();
		}

		// With Meta XR enabled, Get Gaze Data is served by OculusXREyeTracker, which applies WorldToMeters to the
		// already scaled eye positions a second time (GazeOrigin ends up 100x too far from the tracking origin).
		// Replace it with the midpoint between the eyes.
		if (OutData.bLeftEyeValid && OutData.bRightEyeValid)
		{
			OutData.bGazeOriginValid = true;
			OutData.GazeOrigin = (OutData.LeftOrigin + OutData.RightOrigin) * 0.5f;
		}
	}

	FOculusXRFaceState FaceState;
	if (UOculusXRMovementFunctionLibrary::TryGetFaceState(FaceState) && FaceState.bIsValid
		&& FaceState.ExpressionWeights.Num() > static_cast<int32>(EOculusXRFaceExpression::EyesClosedR))
	{
		const float Threshold = CVarBlinkThreshold.GetValueOnGameThread();
		OutData.bBlinkValid = true;
		OutData.bLeftBlink = FaceState.ExpressionWeights[static_cast<int32>(EOculusXRFaceExpression::EyesClosedL)] > Threshold;
		OutData.bRightBlink = FaceState.ExpressionWeights[static_cast<int32>(EOculusXRFaceExpression::EyesClosedR)] > Threshold;
	}

	return OutData.bLeftEyeValid || OutData.bRightEyeValid || OutData.bBlinkValid;
}
