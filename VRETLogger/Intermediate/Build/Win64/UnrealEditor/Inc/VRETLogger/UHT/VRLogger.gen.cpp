// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VRLogger.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeVRLogger() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_VRETLogger();
VRETLOGGER_API UClass* Z_Construct_UClass_ATSVLogger_NoRegister();
VRETLOGGER_API UClass* Z_Construct_UClass_AVRLogger();
VRETLOGGER_API UClass* Z_Construct_UClass_AVRLogger_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AVRLogger Function CalculateAndUpdateHits ********************************
struct Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics
{
	struct VRLogger_eventCalculateAndUpdateHits_Parms
	{
		FVector pos;
		FVector dir;
		FString filterTag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CalculateAndUpdateHits constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_pos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_dir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filterTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CalculateAndUpdateHits constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CalculateAndUpdateHits Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_pos = { "pos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventCalculateAndUpdateHits_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_dir = { "dir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventCalculateAndUpdateHits_Parms, dir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_filterTag = { "filterTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventCalculateAndUpdateHits_Parms, filterTag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_pos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_dir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::NewProp_filterTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::PropPointers) < 2048);
// ********** End Function CalculateAndUpdateHits Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVRLogger, nullptr, "CalculateAndUpdateHits", 	Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::VRLogger_eventCalculateAndUpdateHits_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::VRLogger_eventCalculateAndUpdateHits_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRLogger::execCalculateAndUpdateHits)
{
	P_GET_STRUCT(FVector,Z_Param_pos);
	P_GET_STRUCT(FVector,Z_Param_dir);
	P_GET_PROPERTY(FStrProperty,Z_Param_filterTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CalculateAndUpdateHits(Z_Param_pos,Z_Param_dir,Z_Param_filterTag);
	P_NATIVE_END;
}
// ********** End Class AVRLogger Function CalculateAndUpdateHits **********************************

// ********** Begin Class AVRLogger Function SetDebugShape *****************************************
struct Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics
{
	struct VRLogger_eventSetDebugShape_Parms
	{
		UStaticMeshComponent* shape;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_shape_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDebugShape constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_shape;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDebugShape constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDebugShape Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::NewProp_shape = { "shape", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventSetDebugShape_Parms, shape), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_shape_MetaData), NewProp_shape_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::NewProp_shape,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::PropPointers) < 2048);
// ********** End Function SetDebugShape Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVRLogger, nullptr, "SetDebugShape", 	Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::VRLogger_eventSetDebugShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::VRLogger_eventSetDebugShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRLogger_SetDebugShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRLogger_SetDebugShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRLogger::execSetDebugShape)
{
	P_GET_OBJECT(UStaticMeshComponent,Z_Param_shape);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDebugShape(Z_Param_shape);
	P_NATIVE_END;
}
// ********** End Class AVRLogger Function SetDebugShape *******************************************

// ********** Begin Class AVRLogger Function StartLogging ******************************************
struct Z_Construct_UFunction_AVRLogger_StartLogging_Statics
{
	struct VRLogger_eventStartLogging_Parms
	{
		FString id;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartLogging constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_id;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartLogging constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartLogging Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVRLogger_StartLogging_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventStartLogging_Parms, id), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRLogger_StartLogging_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_StartLogging_Statics::NewProp_id,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_StartLogging_Statics::PropPointers) < 2048);
// ********** End Function StartLogging Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRLogger_StartLogging_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVRLogger, nullptr, "StartLogging", 	Z_Construct_UFunction_AVRLogger_StartLogging_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_StartLogging_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVRLogger_StartLogging_Statics::VRLogger_eventStartLogging_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_StartLogging_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRLogger_StartLogging_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVRLogger_StartLogging_Statics::VRLogger_eventStartLogging_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRLogger_StartLogging()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRLogger_StartLogging_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRLogger::execStartLogging)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_id);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartLogging(Z_Param_id);
	P_NATIVE_END;
}
// ********** End Class AVRLogger Function StartLogging ********************************************

// ********** Begin Class AVRLogger Function UpdateETData ******************************************
struct Z_Construct_UFunction_AVRLogger_UpdateETData_Statics
{
	struct VRLogger_eventUpdateETData_Parms
	{
		float deltaTime;
		FVector headPos;
		FQuat headRot;
		FVector gazeOrigin;
		FVector dir;
		float conf;
		FVector fixPoint;
		bool lBlink;
		bool rBlink;
		float lPupil;
		float rPupil;
		FVector lOrigin;
		FVector lDir;
		FVector rOrigin;
		FVector rDir;
		bool valid;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateETData constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_headPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_headRot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_gazeOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_dir;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_conf;
	static const UECodeGen_Private::FStructPropertyParams NewProp_fixPoint;
	static void NewProp_lBlink_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_lBlink;
	static void NewProp_rBlink_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_rBlink;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_lPupil;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_rPupil;
	static const UECodeGen_Private::FStructPropertyParams NewProp_lOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_lDir;
	static const UECodeGen_Private::FStructPropertyParams NewProp_rOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_rDir;
	static void NewProp_valid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_valid;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateETData constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateETData Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_deltaTime = { "deltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, deltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_headPos = { "headPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, headPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_headRot = { "headRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, headRot), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_gazeOrigin = { "gazeOrigin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, gazeOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_dir = { "dir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, dir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_conf = { "conf", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, conf), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_fixPoint = { "fixPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, fixPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lBlink_SetBit(void* Obj)
{
	((VRLogger_eventUpdateETData_Parms*)Obj)->lBlink = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lBlink = { "lBlink", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRLogger_eventUpdateETData_Parms), &Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lBlink_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rBlink_SetBit(void* Obj)
{
	((VRLogger_eventUpdateETData_Parms*)Obj)->rBlink = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rBlink = { "rBlink", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRLogger_eventUpdateETData_Parms), &Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rBlink_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lPupil = { "lPupil", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, lPupil), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rPupil = { "rPupil", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, rPupil), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lOrigin = { "lOrigin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, lOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lDir = { "lDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, lDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rOrigin = { "rOrigin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, rOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rDir = { "rDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateETData_Parms, rDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_valid_SetBit(void* Obj)
{
	((VRLogger_eventUpdateETData_Parms*)Obj)->valid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_valid = { "valid", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRLogger_eventUpdateETData_Parms), &Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_valid_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_deltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_headPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_headRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_gazeOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_dir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_conf,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_fixPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lBlink,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rBlink,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lPupil,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rPupil,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_lDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_rDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::NewProp_valid,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::PropPointers) < 2048);
// ********** End Function UpdateETData Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVRLogger, nullptr, "UpdateETData", 	Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::VRLogger_eventUpdateETData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::VRLogger_eventUpdateETData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRLogger_UpdateETData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRLogger_UpdateETData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRLogger::execUpdateETData)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_deltaTime);
	P_GET_STRUCT(FVector,Z_Param_headPos);
	P_GET_STRUCT(FQuat,Z_Param_headRot);
	P_GET_STRUCT(FVector,Z_Param_gazeOrigin);
	P_GET_STRUCT(FVector,Z_Param_dir);
	P_GET_PROPERTY(FFloatProperty,Z_Param_conf);
	P_GET_STRUCT(FVector,Z_Param_fixPoint);
	P_GET_UBOOL(Z_Param_lBlink);
	P_GET_UBOOL(Z_Param_rBlink);
	P_GET_PROPERTY(FFloatProperty,Z_Param_lPupil);
	P_GET_PROPERTY(FFloatProperty,Z_Param_rPupil);
	P_GET_STRUCT(FVector,Z_Param_lOrigin);
	P_GET_STRUCT(FVector,Z_Param_lDir);
	P_GET_STRUCT(FVector,Z_Param_rOrigin);
	P_GET_STRUCT(FVector,Z_Param_rDir);
	P_GET_UBOOL(Z_Param_valid);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateETData(Z_Param_deltaTime,Z_Param_headPos,Z_Param_headRot,Z_Param_gazeOrigin,Z_Param_dir,Z_Param_conf,Z_Param_fixPoint,Z_Param_lBlink,Z_Param_rBlink,Z_Param_lPupil,Z_Param_rPupil,Z_Param_lOrigin,Z_Param_lDir,Z_Param_rOrigin,Z_Param_rDir,Z_Param_valid);
	P_NATIVE_END;
}
// ********** End Class AVRLogger Function UpdateETData ********************************************

// ********** Begin Class AVRLogger Function UpdateHits ********************************************
struct Z_Construct_UFunction_AVRLogger_UpdateHits_Statics
{
	struct VRLogger_eventUpdateHits_Parms
	{
		FVector pos;
		FString name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateHits constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_pos;
	static const UECodeGen_Private::FStrPropertyParams NewProp_name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateHits constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateHits Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::NewProp_pos = { "pos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateHits_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRLogger_eventUpdateHits_Parms, name), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::NewProp_pos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::NewProp_name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::PropPointers) < 2048);
// ********** End Function UpdateHits Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AVRLogger, nullptr, "UpdateHits", 	Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::VRLogger_eventUpdateHits_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::VRLogger_eventUpdateHits_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRLogger_UpdateHits()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRLogger_UpdateHits_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRLogger::execUpdateHits)
{
	P_GET_STRUCT(FVector,Z_Param_pos);
	P_GET_PROPERTY(FStrProperty,Z_Param_name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateHits(Z_Param_pos,Z_Param_name);
	P_NATIVE_END;
}
// ********** End Class AVRLogger Function UpdateHits **********************************************

// ********** Begin Class AVRLogger ****************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AVRLogger;
UClass* AVRLogger::GetPrivateStaticClass()
{
	using TClass = AVRLogger;
	if (!Z_Registration_Info_UClass_AVRLogger.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("VRLogger"),
			Z_Registration_Info_UClass_AVRLogger.InnerSingleton,
			StaticRegisterNativesAVRLogger,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AVRLogger.InnerSingleton;
}
UClass* Z_Construct_UClass_AVRLogger_NoRegister()
{
	return AVRLogger::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AVRLogger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "VRLogger.h" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Logger_MetaData[] = {
		{ "Category", "VR Logger" },
		{ "ModuleRelativePath", "Public/VRLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AVRLogger constinit property declarations ********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Logger;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AVRLogger constinit property declarations **********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CalculateAndUpdateHits"), .Pointer = &AVRLogger::execCalculateAndUpdateHits },
		{ .NameUTF8 = UTF8TEXT("SetDebugShape"), .Pointer = &AVRLogger::execSetDebugShape },
		{ .NameUTF8 = UTF8TEXT("StartLogging"), .Pointer = &AVRLogger::execStartLogging },
		{ .NameUTF8 = UTF8TEXT("UpdateETData"), .Pointer = &AVRLogger::execUpdateETData },
		{ .NameUTF8 = UTF8TEXT("UpdateHits"), .Pointer = &AVRLogger::execUpdateHits },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AVRLogger_CalculateAndUpdateHits, "CalculateAndUpdateHits" }, // 2111878611
		{ &Z_Construct_UFunction_AVRLogger_SetDebugShape, "SetDebugShape" }, // 32284879
		{ &Z_Construct_UFunction_AVRLogger_StartLogging, "StartLogging" }, // 1812828630
		{ &Z_Construct_UFunction_AVRLogger_UpdateETData, "UpdateETData" }, // 2880864497
		{ &Z_Construct_UFunction_AVRLogger_UpdateHits, "UpdateHits" }, // 2196601025
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRLogger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AVRLogger_Statics

// ********** Begin Class AVRLogger Property Definitions *******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRLogger_Statics::NewProp_Logger = { "Logger", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRLogger, Logger), Z_Construct_UClass_ATSVLogger_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Logger_MetaData), NewProp_Logger_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVRLogger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRLogger_Statics::NewProp_Logger,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRLogger_Statics::PropPointers) < 2048);
// ********** End Class AVRLogger Property Definitions *********************************************
UObject* (*const Z_Construct_UClass_AVRLogger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VRETLogger,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRLogger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRLogger_Statics::ClassParams = {
	&AVRLogger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AVRLogger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AVRLogger_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRLogger_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRLogger_Statics::Class_MetaDataParams)
};
void AVRLogger::StaticRegisterNativesAVRLogger()
{
	UClass* Class = AVRLogger::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AVRLogger_Statics::Funcs));
}
UClass* Z_Construct_UClass_AVRLogger()
{
	if (!Z_Registration_Info_UClass_AVRLogger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRLogger.OuterSingleton, Z_Construct_UClass_AVRLogger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRLogger.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AVRLogger);
AVRLogger::~AVRLogger() {}
// ********** End Class AVRLogger ******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h__Script_VRETLogger_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRLogger, AVRLogger::StaticClass, TEXT("AVRLogger"), &Z_Registration_Info_UClass_AVRLogger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRLogger), 319785000U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h__Script_VRETLogger_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h__Script_VRETLogger_3830107434{
	TEXT("/Script/VRETLogger"),
	Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h__Script_VRETLogger_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_VRLogger_h__Script_VRETLogger_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
