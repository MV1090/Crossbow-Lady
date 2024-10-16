// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossbowLadyGameMode.h"

void ACrossbowLadyGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine ->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is Crossbow Lady Stated!"));
}