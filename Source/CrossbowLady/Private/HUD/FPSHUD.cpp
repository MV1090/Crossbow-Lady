// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"

void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowGameMenu(GameWidget);
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AFPSHUD::ShowGameMenu(TSubclassOf<UGameHUDWidget> newGameWidget)
{
	if (gameWidgetContainer) {
		gameWidgetContainer->RemoveFromParent();
		gameWidgetContainer = nullptr;
	}

	if (newGameWidget) {
		gameWidgetContainer = CreateWidget<UGameHUDWidget>(GetWorld(), newGameWidget);
		gameWidgetContainer->AddToViewport();
	}
}
