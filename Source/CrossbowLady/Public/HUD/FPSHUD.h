// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "GUI/GameHUDWidget.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// 1. HUD method of making UI
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameHUDWidget> GameWidget;

	UPROPERTY()
	UGameHUDWidget* gameWidgetContainer;

	void ShowGameMenu(TSubclassOf<UGameHUDWidget> newGameWidget);

protected:

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;
};
