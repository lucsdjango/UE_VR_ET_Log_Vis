// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/IModularFeatures.h"
#include "MetaXREyeDataProvider.h"
#include "Modules/ModuleManager.h"

class FVRETLoggerMetaXRModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		IModularFeatures::Get().RegisterModularFeature(IVRETEyeDataProvider::GetModularFeatureName(), &Provider);
	}

	virtual void ShutdownModule() override
	{
		IModularFeatures::Get().UnregisterModularFeature(IVRETEyeDataProvider::GetModularFeatureName(), &Provider);
	}

private:
	FMetaXREyeDataProvider Provider;
};

IMPLEMENT_MODULE(FVRETLoggerMetaXRModule, VRETLoggerMetaXR);
