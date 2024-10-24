// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "CrossbowLadyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API ACrossbowLadyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	
};
