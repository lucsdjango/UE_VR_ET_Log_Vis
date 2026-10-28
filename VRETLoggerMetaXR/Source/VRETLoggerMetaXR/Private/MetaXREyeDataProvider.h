// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRETEyeDataProvider.h"

// Per-eye gaze (XR_FB_eye_tracking_social) and blinks (XR_FB_face_tracking2 eyelid weights) from the Meta XR plugin.
// Meta does not expose pupil diameter, so those columns stay at 0.
class FMetaXREyeDataProvider : public IVRETEyeDataProvider
{
public:
	virtual FString GetProviderName() const override { return TEXT("Meta XR"); }
	virtual void StartTracking() override;
	virtual bool GetEyeData(FVRETEyeData& OutData) override;

private:
	double LastStartAttemptTime = -1.0;
};
