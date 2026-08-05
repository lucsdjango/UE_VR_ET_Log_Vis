// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TSVLogger.h"

#ifdef VRETLOGGER_TSVLogger_generated_h
#error "TSVLogger.generated.h already included, missing '#pragma once' in TSVLogger.h"
#endif
#define VRETLOGGER_TSVLogger_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ATSVLogger ***************************************************************
#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncLog); \
	DECLARE_FUNCTION(execStartLogging); \
	DECLARE_FUNCTION(execInitOrReset); \
	DECLARE_FUNCTION(execUpdateQuat); \
	DECLARE_FUNCTION(execUpdateInt); \
	DECLARE_FUNCTION(execUpdateFloat); \
	DECLARE_FUNCTION(execUpdateDouble); \
	DECLARE_FUNCTION(execUpdateVector); \
	DECLARE_FUNCTION(execUpdateEntry); \
	DECLARE_FUNCTION(execAddEntry);


struct Z_Construct_UClass_ATSVLogger_Statics;
VRETLOGGER_API UClass* Z_Construct_UClass_ATSVLogger_NoRegister();

#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATSVLogger(); \
	friend struct ::Z_Construct_UClass_ATSVLogger_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend VRETLOGGER_API UClass* ::Z_Construct_UClass_ATSVLogger_NoRegister(); \
public: \
	DECLARE_CLASS2(ATSVLogger, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VRETLogger"), Z_Construct_UClass_ATSVLogger_NoRegister) \
	DECLARE_SERIALIZER(ATSVLogger)


#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ATSVLogger(ATSVLogger&&) = delete; \
	ATSVLogger(const ATSVLogger&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATSVLogger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATSVLogger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATSVLogger) \
	NO_API virtual ~ATSVLogger();


#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_9_PROLOG
#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ATSVLogger;

// ********** End Class ATSVLogger *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
