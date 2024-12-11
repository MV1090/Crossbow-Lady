// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GUI/MainMenu.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override; 

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainMenu> MainMenuWidget;

	UPROPERTY()
	
	UMainMenu* MenuWidgetContainer;
	
	void ShowMainMenu(TSubclassOf<UMainMenu> newGameWidget);
};
