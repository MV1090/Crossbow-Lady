// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CrossbowLady/CBLady.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCBLady() {}
// Cross Module References
	CROSSBOWLADY_API UClass* Z_Construct_UClass_ACBLady();
	CROSSBOWLADY_API UClass* Z_Construct_UClass_ACBLady_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CrossbowLady();
// End Cross Module References
	DEFINE_FUNCTION(ACBLady::execStopJump)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopJump();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACBLady::execStartJump)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartJump();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACBLady::execMoveRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveRight(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACBLady::execMoveForward)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveForward(Z_Param_value);
		P_NATIVE_END;
	}
	void ACBLady::StaticRegisterNativesACBLady()
	{
		UClass* Class = ACBLady::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveForward", &ACBLady::execMoveForward },
			{ "MoveRight", &ACBLady::execMoveRight },
			{ "StartJump", &ACBLady::execStartJump },
			{ "StopJump", &ACBLady::execStopJump },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACBLady_MoveForward_Statics
	{
		struct CBLady_eventMoveForward_Parms
		{
			float value;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACBLady_MoveForward_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLady_eventMoveForward_Parms, value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACBLady_MoveForward_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACBLady_MoveForward_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACBLady_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACBLady_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACBLady, nullptr, "MoveForward", nullptr, nullptr, Z_Construct_UFunction_ACBLady_MoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveForward_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACBLady_MoveForward_Statics::CBLady_eventMoveForward_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveForward_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACBLady_MoveForward_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveForward_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACBLady_MoveForward_Statics::CBLady_eventMoveForward_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACBLady_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACBLady_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACBLady_MoveRight_Statics
	{
		struct CBLady_eventMoveRight_Parms
		{
			float Value;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACBLady_MoveRight_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CBLady_eventMoveRight_Parms, Value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACBLady_MoveRight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACBLady_MoveRight_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACBLady_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACBLady_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACBLady, nullptr, "MoveRight", nullptr, nullptr, Z_Construct_UFunction_ACBLady_MoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveRight_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACBLady_MoveRight_Statics::CBLady_eventMoveRight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveRight_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACBLady_MoveRight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_MoveRight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACBLady_MoveRight_Statics::CBLady_eventMoveRight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACBLady_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACBLady_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACBLady_StartJump_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACBLady_StartJump_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACBLady_StartJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACBLady, nullptr, "StartJump", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_StartJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACBLady_StartJump_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ACBLady_StartJump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACBLady_StartJump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACBLady_StopJump_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACBLady_StopJump_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACBLady_StopJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACBLady, nullptr, "StopJump", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACBLady_StopJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACBLady_StopJump_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ACBLady_StopJump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACBLady_StopJump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACBLady);
	UClass* Z_Construct_UClass_ACBLady_NoRegister()
	{
		return ACBLady::StaticClass();
	}
	struct Z_Construct_UClass_ACBLady_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FPSCameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FPSCameraComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FPSMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FPSMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACBLady_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CrossbowLady,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ACBLady_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACBLady_MoveForward, "MoveForward" }, // 1986954619
		{ &Z_Construct_UFunction_ACBLady_MoveRight, "MoveRight" }, // 1632156147
		{ &Z_Construct_UFunction_ACBLady_StartJump, "StartJump" }, // 4219021058
		{ &Z_Construct_UFunction_ACBLady_StopJump, "StopJump" }, // 727160592
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACBLady_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CBLady.h" },
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACBLady_Statics::NewProp_FPSCameraComponent_MetaData[] = {
		{ "Category", "CBLady" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACBLady_Statics::NewProp_FPSCameraComponent = { "FPSCameraComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACBLady, FPSCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::NewProp_FPSCameraComponent_MetaData), Z_Construct_UClass_ACBLady_Statics::NewProp_FPSCameraComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACBLady_Statics::NewProp_FPSMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CBLady.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACBLady_Statics::NewProp_FPSMesh = { "FPSMesh", nullptr, (EPropertyFlags)0x00100000000b0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACBLady, FPSMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::NewProp_FPSMesh_MetaData), Z_Construct_UClass_ACBLady_Statics::NewProp_FPSMesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACBLady_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACBLady_Statics::NewProp_FPSCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACBLady_Statics::NewProp_FPSMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACBLady_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACBLady>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACBLady_Statics::ClassParams = {
		&ACBLady::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACBLady_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::Class_MetaDataParams), Z_Construct_UClass_ACBLady_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACBLady_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACBLady()
	{
		if (!Z_Registration_Info_UClass_ACBLady.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACBLady.OuterSingleton, Z_Construct_UClass_ACBLady_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACBLady.OuterSingleton;
	}
	template<> CROSSBOWLADY_API UClass* StaticClass<ACBLady>()
	{
		return ACBLady::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACBLady);
	ACBLady::~ACBLady() {}
	struct Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CBLady_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CBLady_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACBLady, ACBLady::StaticClass, TEXT("ACBLady"), &Z_Registration_Info_UClass_ACBLady, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACBLady), 1547186657U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CBLady_h_93215216(TEXT("/Script/CrossbowLady"),
		Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CBLady_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CBLady_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
