// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainMenuHUD.h"

void AMainMenuHUD::BeginPlay()
{
	ShowMainMenu(MainMenuWidget);
}

void AMainMenuHUD::ShowMainMenu(TSubclassOf<UMainMenu> newGameWidget)
{
	if (MenuWidgetContainer) {
		MenuWidgetContainer->RemoveFromParent();
		MenuWidgetContainer = nullptr;
	}

	if (newGameWidget) {
		MenuWidgetContainer = CreateWidget<UMainMenu>(GetWorld(), newGameWidget);
		MenuWidgetContainer->AddToViewport();
	}
}
