// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CrossbowLady/CrossbowLadyGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrossbowLadyGameMode() {}
// Cross Module References
	CROSSBOWLADY_API UClass* Z_Construct_UClass_ACrossbowLadyGameMode();
	CROSSBOWLADY_API UClass* Z_Construct_UClass_ACrossbowLadyGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CrossbowLady();
// End Cross Module References
	void ACrossbowLadyGameMode::StaticRegisterNativesACrossbowLadyGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACrossbowLadyGameMode);
	UClass* Z_Construct_UClass_ACrossbowLadyGameMode_NoRegister()
	{
		return ACrossbowLadyGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACrossbowLadyGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACrossbowLadyGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CrossbowLady,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACrossbowLadyGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrossbowLadyGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CrossbowLadyGameMode.h" },
		{ "ModuleRelativePath", "CrossbowLadyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACrossbowLadyGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrossbowLadyGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACrossbowLadyGameMode_Statics::ClassParams = {
		&ACrossbowLadyGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACrossbowLadyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACrossbowLadyGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ACrossbowLadyGameMode()
	{
		if (!Z_Registration_Info_UClass_ACrossbowLadyGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACrossbowLadyGameMode.OuterSingleton, Z_Construct_UClass_ACrossbowLadyGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACrossbowLadyGameMode.OuterSingleton;
	}
	template<> CROSSBOWLADY_API UClass* StaticClass<ACrossbowLadyGameMode>()
	{
		return ACrossbowLadyGameMode::StaticClass();
	}
	ACrossbowLadyGameMode::ACrossbowLadyGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACrossbowLadyGameMode);
	ACrossbowLadyGameMode::~ACrossbowLadyGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CrossbowLadyGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CrossbowLadyGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACrossbowLadyGameMode, ACrossbowLadyGameMode::StaticClass, TEXT("ACrossbowLadyGameMode"), &Z_Registration_Info_UClass_ACrossbowLadyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACrossbowLadyGameMode), 2878629897U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CrossbowLadyGameMode_h_2634491186(TEXT("/Script/CrossbowLady"),
		Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CrossbowLadyGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Mark__Desktop_Crossbow_Lady_CrossbowLady_Source_CrossbowLady_CrossbowLadyGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
