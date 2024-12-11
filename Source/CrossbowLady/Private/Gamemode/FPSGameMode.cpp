// Fill out your copyright notice in the Description page of Project Settings.

#include "Gamemode/FPSGameMode.h"

AFPSGameMode::AFPSGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AFPSGameMode::StartPlay()
{
	Super::StartPlay();	
}

void AFPSGameMode::BeginPlay()
{
	Super::BeginPlay();
	RunTriggerableTimer();
}


void AFPSGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetWorld()->GetTimerManager().IsTimerActive(DelayTimerHandle))
	{
		// Set a one-shot timer to call the Timer function after 1 second
		GetWorld()->GetTimerManager().SetTimer(DelayTimerHandle, this, &AFPSGameMode::Timer, 1.0f, false);
	}
}

void AFPSGameMode::Timer()
{
	Seconds++;

	if (Seconds > 59)
	{
		Minutes++;
		Seconds = 0;
	}
	check(GEngine != nullptr);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Time: %i"), Seconds));
}

void AFPSGameMode::RunTriggerableTimer()
{
	//GetWorld()->GetTimerManager().ClearTimer(DelayTimerHandle);	
	GetWorld()->GetTimerManager().SetTimer(DelayTimerHandle, this, &AFPSGameMode::Timer, 1.0f, false);
}
