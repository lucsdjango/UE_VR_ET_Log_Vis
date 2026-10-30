// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRETEyeDataProvider.h"

// Per-eye gaze, blinks, pupil diameter (mm) and focus distance from the Varjo Native SDK. Reads the latest gaze sample
// once per engine frame, through a native Varjo session running alongside the engine's OpenXR session.
class FVarjoEyeDataProvider : public IVRETEyeDataProvider
{
public:
	virtual ~FVarjoEyeDataProvider();

	virtual FString GetProviderName() const override { return TEXT("Varjo Native SDK"); }
	virtual void StartTracking() override;
	virtual bool GetEyeData(FVRETEyeData& OutData) override;

private:
	struct varjo_Session* Session = nullptr;
	bool bGazeInitialized = false;
	double LastStartAttemptTime = -1.0;
};
