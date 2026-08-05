// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VRLogger.h"

#ifdef VRETLOGGER_VRLogger_generated_h
#error "VRLogger.generated.h already included, missing '#pragma once' in VRLogger.h"
#endif
#define VRETLOGGER_VRLogger_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMeshComponent;

// ********** Begin Class AVRLogger ****************************************************************
#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCalculateAndUpdateHits); \
	DECLARE_FUNCTION(execUpdateHits); \
	DECLARE_FUNCTION(execUpdateETData); \
	DECLARE_FUNCTION(execSetDebugShape); \
	DECLARE_FUNCTION(execStartLogging);


struct Z_Construct_UClass_AVRLogger_Statics;
VRETLOGGER_API UClass* Z_Construct_UClass_AVRLogger_NoRegister();

#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRLogger(); \
	friend struct ::Z_Construct_UClass_AVRLogger_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend VRETLOGGER_API UClass* ::Z_Construct_UClass_AVRLogger_NoRegister(); \
public: \
	DECLARE_CLASS2(AVRLogger, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VRETLogger"), Z_Construct_UClass_AVRLogger_NoRegister) \
	DECLARE_SERIALIZER(AVRLogger)


#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AVRLogger(AVRLogger&&) = delete; \
	AVRLogger(const AVRLogger&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRLogger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRLogger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVRLogger) \
	NO_API virtual ~AVRLogger();


#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_10_PROLOG
#define FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AVRLogger;

// ********** End Class AVRLogger ******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
