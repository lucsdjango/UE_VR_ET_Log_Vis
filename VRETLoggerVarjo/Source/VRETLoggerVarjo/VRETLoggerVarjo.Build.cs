// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using Microsoft.Extensions.Logging;
using UnrealBuildTool;

public class VRETLoggerVarjo : ModuleRules
{
	public VRETLoggerVarjo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		PrivateDependencyModuleNames.AddRange(new string[] { "HeadMountedDisplay", "Projects", "VRETLogger" });

		// Varjo Native SDK: set VARJO_SDK_DIR to the extracted varjo-sdk folder, or copy that folder to Source/ThirdParty/VarjoSDK.
		// Without it the module still builds, but no eye data provider is registered.
		string SdkDir = Environment.GetEnvironmentVariable("VARJO_SDK_DIR");
		if (string.IsNullOrEmpty(SdkDir))
		{
			SdkDir = Path.Combine(PluginDirectory, "Source", "ThirdParty", "VarjoSDK");
		}
		string IncludeDir = Path.Combine(SdkDir, "include");
		string LibPath = Path.Combine(SdkDir, "lib", "VarjoLib.lib");
		string DllPath = Path.Combine(SdkDir, "bin", "VarjoLib.dll");

		bool bHasSdk = File.Exists(Path.Combine(IncludeDir, "Varjo.h")) && File.Exists(LibPath);
		if (bHasSdk)
		{
			PrivateIncludePaths.Add(IncludeDir);
			PublicAdditionalLibraries.Add(LibPath);
			PublicDelayLoadDLLs.Add("VarjoLib.dll");
			if (File.Exists(DllPath))
			{
				RuntimeDependencies.Add("$(BinaryOutputDir)/VarjoLib.dll", DllPath);
			}
		}
		else
		{
			Logger.LogWarning("VRETLoggerVarjo: Varjo Native SDK not found in '{SdkDir}' (expected include/Varjo.h and lib/VarjoLib.lib). Building without Varjo eye data.", SdkDir);
		}
		PrivateDefinitions.Add("WITH_VARJO_SDK=" + (bHasSdk ? "1" : "0"));
	}
}
