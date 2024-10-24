// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossbowLadyGameMode.h"

void ACrossbowLadyGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine ->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, Crossbow Lady Stated!"));

	//Print to out put
	//int test = 10;
	//bool boolTest = true;
	//UE_LOG(LogTemp, Warning, TEXT("Test: %i, TestBool; %d"), test, boolTest);

	//new print to output
	//UE_LOGFMT(LogTemp, Warning, "Test: {0}, TestBool: {1}", test, boolTest);
}