// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UFUNCTION()
	void SetHealthBar(float percentage);

	UFUNCTION()
	void SetScoreText(int amount);

private:

	int UIScore;

};
