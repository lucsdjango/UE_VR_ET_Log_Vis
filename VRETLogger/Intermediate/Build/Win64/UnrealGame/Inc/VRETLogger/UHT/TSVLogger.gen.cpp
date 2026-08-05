// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TSVLogger.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTSVLogger() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_VRETLogger();
VRETLOGGER_API UClass* Z_Construct_UClass_ATSVLogger();
VRETLOGGER_API UClass* Z_Construct_UClass_ATSVLogger_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATSVLogger Function AddEntry *********************************************
struct Z_Construct_UFunction_ATSVLogger_AddEntry_Statics
{
	struct TSVLogger_eventAddEntry_Parms
	{
		FString k;
		FString defVal;
		bool resetEachFrame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "CPP_Default_defVal", "" },
		{ "CPP_Default_resetEachFrame", "false" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddEntry constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FStrPropertyParams NewProp_defVal;
	static void NewProp_resetEachFrame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_resetEachFrame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddEntry constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddEntry Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventAddEntry_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_defVal = { "defVal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventAddEntry_Parms, defVal), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_resetEachFrame_SetBit(void* Obj)
{
	((TSVLogger_eventAddEntry_Parms*)Obj)->resetEachFrame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_resetEachFrame = { "resetEachFrame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TSVLogger_eventAddEntry_Parms), &Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_resetEachFrame_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_defVal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::NewProp_resetEachFrame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::PropPointers) < 2048);
// ********** End Function AddEntry Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "AddEntry", 	Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::TSVLogger_eventAddEntry_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::TSVLogger_eventAddEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_AddEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_AddEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execAddEntry)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_PROPERTY(FStrProperty,Z_Param_defVal);
	P_GET_UBOOL(Z_Param_resetEachFrame);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddEntry(Z_Param_k,Z_Param_defVal,Z_Param_resetEachFrame);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function AddEntry ***********************************************

// ********** Begin Class ATSVLogger Function AsyncLog *********************************************
struct Z_Construct_UFunction_ATSVLogger_AsyncLog_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncLog constinit property declarations ******************************
// ********** End Function AsyncLog constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_AsyncLog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "AsyncLog", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_AsyncLog_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_AsyncLog_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ATSVLogger_AsyncLog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_AsyncLog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execAsyncLog)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AsyncLog();
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function AsyncLog ***********************************************

// ********** Begin Class ATSVLogger Function InitOrReset ******************************************
struct Z_Construct_UFunction_ATSVLogger_InitOrReset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitOrReset constinit property declarations ***************************
// ********** End Function InitOrReset constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_InitOrReset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "InitOrReset", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_InitOrReset_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_InitOrReset_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ATSVLogger_InitOrReset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_InitOrReset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execInitOrReset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitOrReset();
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function InitOrReset ********************************************

// ********** Begin Class ATSVLogger Function StartLogging *****************************************
struct Z_Construct_UFunction_ATSVLogger_StartLogging_Statics
{
	struct TSVLogger_eventStartLogging_Parms
	{
		FString id;
		bool async;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "CPP_Default_async", "false" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartLogging constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_id;
	static void NewProp_async_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_async;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartLogging constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartLogging Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventStartLogging_Parms, id), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_async_SetBit(void* Obj)
{
	((TSVLogger_eventStartLogging_Parms*)Obj)->async = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_async = { "async", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TSVLogger_eventStartLogging_Parms), &Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_async_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::NewProp_async,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::PropPointers) < 2048);
// ********** End Function StartLogging Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "StartLogging", 	Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::TSVLogger_eventStartLogging_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::TSVLogger_eventStartLogging_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_StartLogging()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_StartLogging_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execStartLogging)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_id);
	P_GET_UBOOL(Z_Param_async);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartLogging(Z_Param_id,Z_Param_async);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function StartLogging *******************************************

// ********** Begin Class ATSVLogger Function UpdateDouble *****************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics
{
	struct TSVLogger_eventUpdateDouble_Parms
	{
		FString k;
		double v;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateDouble constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_v;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateDouble constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateDouble Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateDouble_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::NewProp_v = { "v", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateDouble_Parms, v), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::NewProp_v,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::PropPointers) < 2048);
// ********** End Function UpdateDouble Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateDouble", 	Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::TSVLogger_eventUpdateDouble_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::TSVLogger_eventUpdateDouble_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateDouble()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateDouble_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateDouble)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_PROPERTY(FDoubleProperty,Z_Param_v);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateDouble(Z_Param_k,Z_Param_v);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateDouble *******************************************

// ********** Begin Class ATSVLogger Function UpdateEntry ******************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics
{
	struct TSVLogger_eventUpdateEntry_Parms
	{
		FString k;
		FString v;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "CPP_Default_v", "" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateEntry constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FStrPropertyParams NewProp_v;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateEntry constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateEntry Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateEntry_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::NewProp_v = { "v", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateEntry_Parms, v), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::NewProp_v,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::PropPointers) < 2048);
// ********** End Function UpdateEntry Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateEntry", 	Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::TSVLogger_eventUpdateEntry_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::TSVLogger_eventUpdateEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateEntry)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_PROPERTY(FStrProperty,Z_Param_v);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateEntry(Z_Param_k,Z_Param_v);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateEntry ********************************************

// ********** Begin Class ATSVLogger Function UpdateFloat ******************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics
{
	struct TSVLogger_eventUpdateFloat_Parms
	{
		FString k;
		float v;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateFloat constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_v;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateFloat constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateFloat Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateFloat_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::NewProp_v = { "v", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateFloat_Parms, v), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::NewProp_v,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::PropPointers) < 2048);
// ********** End Function UpdateFloat Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateFloat", 	Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::TSVLogger_eventUpdateFloat_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::TSVLogger_eventUpdateFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateFloat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_PROPERTY(FFloatProperty,Z_Param_v);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateFloat(Z_Param_k,Z_Param_v);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateFloat ********************************************

// ********** Begin Class ATSVLogger Function UpdateInt ********************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics
{
	struct TSVLogger_eventUpdateInt_Parms
	{
		FString k;
		int32 v;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateInt constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FIntPropertyParams NewProp_v;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateInt constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateInt Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateInt_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::NewProp_v = { "v", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateInt_Parms, v), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::NewProp_v,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::PropPointers) < 2048);
// ********** End Function UpdateInt Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateInt", 	Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::TSVLogger_eventUpdateInt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::TSVLogger_eventUpdateInt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateInt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateInt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateInt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_PROPERTY(FIntProperty,Z_Param_v);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateInt(Z_Param_k,Z_Param_v);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateInt **********************************************

// ********** Begin Class ATSVLogger Function UpdateQuat *******************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics
{
	struct TSVLogger_eventUpdateQuat_Parms
	{
		FString k;
		FQuat q;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateQuat constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FStructPropertyParams NewProp_q;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateQuat constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateQuat Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateQuat_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::NewProp_q = { "q", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateQuat_Parms, q), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::NewProp_q,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::PropPointers) < 2048);
// ********** End Function UpdateQuat Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateQuat", 	Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::TSVLogger_eventUpdateQuat_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::TSVLogger_eventUpdateQuat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateQuat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateQuat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateQuat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_STRUCT(FQuat,Z_Param_q);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateQuat(Z_Param_k,Z_Param_q);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateQuat *********************************************

// ********** Begin Class ATSVLogger Function UpdateVector *****************************************
struct Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics
{
	struct TSVLogger_eventUpdateVector_Parms
	{
		FString k;
		FVector v;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "TSV Logger" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateVector constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_k;
	static const UECodeGen_Private::FStructPropertyParams NewProp_v;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateVector constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateVector Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::NewProp_k = { "k", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateVector_Parms, k), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::NewProp_v = { "v", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TSVLogger_eventUpdateVector_Parms, v), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::NewProp_k,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::NewProp_v,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::PropPointers) < 2048);
// ********** End Function UpdateVector Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATSVLogger, nullptr, "UpdateVector", 	Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::TSVLogger_eventUpdateVector_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::TSVLogger_eventUpdateVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATSVLogger_UpdateVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATSVLogger_UpdateVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATSVLogger::execUpdateVector)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_k);
	P_GET_STRUCT(FVector,Z_Param_v);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateVector(Z_Param_k,Z_Param_v);
	P_NATIVE_END;
}
// ********** End Class ATSVLogger Function UpdateVector *******************************************

// ********** Begin Class ATSVLogger ***************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ATSVLogger;
UClass* ATSVLogger::GetPrivateStaticClass()
{
	using TClass = ATSVLogger;
	if (!Z_Registration_Info_UClass_ATSVLogger.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TSVLogger"),
			Z_Registration_Info_UClass_ATSVLogger.InnerSingleton,
			StaticRegisterNativesATSVLogger,
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
	return Z_Registration_Info_UClass_ATSVLogger.InnerSingleton;
}
UClass* Z_Construct_UClass_ATSVLogger_NoRegister()
{
	return ATSVLogger::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATSVLogger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "TSVLogger.h" },
		{ "ModuleRelativePath", "Public/TSVLogger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ATSVLogger constinit property declarations *******************************
// ********** End Class ATSVLogger constinit property declarations *********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddEntry"), .Pointer = &ATSVLogger::execAddEntry },
		{ .NameUTF8 = UTF8TEXT("AsyncLog"), .Pointer = &ATSVLogger::execAsyncLog },
		{ .NameUTF8 = UTF8TEXT("InitOrReset"), .Pointer = &ATSVLogger::execInitOrReset },
		{ .NameUTF8 = UTF8TEXT("StartLogging"), .Pointer = &ATSVLogger::execStartLogging },
		{ .NameUTF8 = UTF8TEXT("UpdateDouble"), .Pointer = &ATSVLogger::execUpdateDouble },
		{ .NameUTF8 = UTF8TEXT("UpdateEntry"), .Pointer = &ATSVLogger::execUpdateEntry },
		{ .NameUTF8 = UTF8TEXT("UpdateFloat"), .Pointer = &ATSVLogger::execUpdateFloat },
		{ .NameUTF8 = UTF8TEXT("UpdateInt"), .Pointer = &ATSVLogger::execUpdateInt },
		{ .NameUTF8 = UTF8TEXT("UpdateQuat"), .Pointer = &ATSVLogger::execUpdateQuat },
		{ .NameUTF8 = UTF8TEXT("UpdateVector"), .Pointer = &ATSVLogger::execUpdateVector },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATSVLogger_AddEntry, "AddEntry" }, // 3480544014
		{ &Z_Construct_UFunction_ATSVLogger_AsyncLog, "AsyncLog" }, // 2506882661
		{ &Z_Construct_UFunction_ATSVLogger_InitOrReset, "InitOrReset" }, // 3369721624
		{ &Z_Construct_UFunction_ATSVLogger_StartLogging, "StartLogging" }, // 201415484
		{ &Z_Construct_UFunction_ATSVLogger_UpdateDouble, "UpdateDouble" }, // 3451102483
		{ &Z_Construct_UFunction_ATSVLogger_UpdateEntry, "UpdateEntry" }, // 2521692121
		{ &Z_Construct_UFunction_ATSVLogger_UpdateFloat, "UpdateFloat" }, // 196507981
		{ &Z_Construct_UFunction_ATSVLogger_UpdateInt, "UpdateInt" }, // 2021396226
		{ &Z_Construct_UFunction_ATSVLogger_UpdateQuat, "UpdateQuat" }, // 1336458453
		{ &Z_Construct_UFunction_ATSVLogger_UpdateVector, "UpdateVector" }, // 3956430255
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATSVLogger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ATSVLogger_Statics
UObject* (*const Z_Construct_UClass_ATSVLogger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VRETLogger,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATSVLogger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATSVLogger_Statics::ClassParams = {
	&ATSVLogger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATSVLogger_Statics::Class_MetaDataParams), Z_Construct_UClass_ATSVLogger_Statics::Class_MetaDataParams)
};
void ATSVLogger::StaticRegisterNativesATSVLogger()
{
	UClass* Class = ATSVLogger::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ATSVLogger_Statics::Funcs));
}
UClass* Z_Construct_UClass_ATSVLogger()
{
	if (!Z_Registration_Info_UClass_ATSVLogger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATSVLogger.OuterSingleton, Z_Construct_UClass_ATSVLogger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATSVLogger.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATSVLogger);
ATSVLogger::~ATSVLogger() {}
// ********** End Class ATSVLogger *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h__Script_VRETLogger_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATSVLogger, ATSVLogger::StaticClass, TEXT("ATSVLogger"), &Z_Registration_Info_UClass_ATSVLogger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATSVLogger), 3448988628U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h__Script_VRETLogger_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h__Script_VRETLogger_2779851342{
	TEXT("/Script/VRETLogger"),
	Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h__Script_VRETLogger_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_plust_Documents_Unreal_Projects_UE_VR_ET_Visualization_PluginExport_VRETLogger_HostProject_Plugins_VRETLogger_Source_VRETLogger_Public_TSVLogger_h__Script_VRETLogger_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
