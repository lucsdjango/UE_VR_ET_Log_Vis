// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/IModularFeatures.h"
#include "HAL/PlatformProcess.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "VarjoEyeDataProvider.h"

class FVRETLoggerVarjoModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
#if WITH_VARJO_SDK
		// VarjoLib.dll is delay loaded. Load it explicitly (next to the plugin binary, else from the system path) so a
		// missing DLL disables the provider instead of crashing on the first Varjo call.
		const FString DllDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("VRETLoggerVarjo"))->GetBaseDir(), TEXT("Binaries/Win64"));
		FPlatformProcess::PushDllDirectory(*DllDir);
		VarjoLibHandle = FPlatformProcess::GetDllHandle(TEXT("VarjoLib.dll"));
		FPlatformProcess::PopDllDirectory(*DllDir);
		if (!VarjoLibHandle)
		{
			UE_LOG(LogTemp, Warning, TEXT("VRETLoggerVarjo: VarjoLib.dll not found, Varjo eye data is unavailable."));
			return;
		}

		Provider = MakeUnique<FVarjoEyeDataProvider>();
		IModularFeatures::Get().RegisterModularFeature(IVRETEyeDataProvider::GetModularFeatureName(), Provider.Get());
#else
		UE_LOG(LogTemp, Warning, TEXT("VRETLoggerVarjo: built without the Varjo Native SDK, Varjo eye data is unavailable."));
#endif
	}

	virtual void ShutdownModule() override
	{
#if WITH_VARJO_SDK
		if (Provider)
		{
			IModularFeatures::Get().UnregisterModularFeature(IVRETEyeDataProvider::GetModularFeatureName(), Provider.Get());
			Provider.Reset();
		}
		if (VarjoLibHandle)
		{
			FPlatformProcess::FreeDllHandle(VarjoLibHandle);
			VarjoLibHandle = nullptr;
		}
#endif
	}

#if WITH_VARJO_SDK
private:
	TUniquePtr<FVarjoEyeDataProvider> Provider;
	void* VarjoLibHandle = nullptr;
#endif
};

IMPLEMENT_MODULE(FVRETLoggerVarjoModule, VRETLoggerVarjo);
