// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	AFPSGameMode();

	virtual void StartPlay() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	int Seconds;
	int Minutes;

private:

	void Timer();

	FTimerHandle DelayTimerHandle;
	FTimerDelegate FunctionDelegate;
	void RunTriggerableTimer();
};
