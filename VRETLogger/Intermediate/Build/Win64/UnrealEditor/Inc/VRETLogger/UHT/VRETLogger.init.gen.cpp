// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRETLogger_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VRETLogger;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VRETLogger()
	{
		if (!Z_Registration_Info_UPackage__Script_VRETLogger.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/VRETLogger",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x844EF31A,
			0x413349F9,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VRETLogger.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_VRETLogger.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VRETLogger(Z_Construct_UPackage__Script_VRETLogger, TEXT("/Script/VRETLogger"), Z_Registration_Info_UPackage__Script_VRETLogger, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x844EF31A, 0x413349F9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
