// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeature.h"

// Per-eye data that Unreal's generic EyeTracker interface does not provide with OpenXR. All positions/directions in world space.
struct FVRETEyeData
{
	bool bLeftEyeValid = false;
	FVector LeftOrigin = FVector::ZeroVector;
	FVector LeftDirection = FVector::ZeroVector;

	bool bRightEyeValid = false;
	FVector RightOrigin = FVector::ZeroVector;
	FVector RightDirection = FVector::ZeroVector;

	bool bBlinkValid = false;
	bool bLeftBlink = false;
	bool bRightBlink = false;

	bool bPupilValid = false;
	float LeftPupilDiameter = 0.0f;
	float RightPupilDiameter = 0.0f;
};

// Implemented by headset specific companion plugins (e.g. VRETLoggerMetaXR) and registered as a modular feature.
// AVRLogger uses the first registered provider to fill in the per-eye columns.
class IVRETEyeDataProvider : public IModularFeature
{
public:
	static FName GetModularFeatureName()
	{
		static const FName FeatureName = TEXT("VRETEyeDataProvider");
		return FeatureName;
	}

	virtual FString GetProviderName() const = 0;

	// Called when logging starts. Tracking may not be startable yet (no XR session), so GetEyeData should retry if needed.
	virtual void StartTracking() = 0;

	// Returns false if no data is available this frame. Fields with their valid flag unset are ignored.
	virtual bool GetEyeData(FVRETEyeData& OutData) = 0;
};
