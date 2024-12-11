// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Gamemode/FPSGameMode.h"
#include "Blueprint/UserWidget.h"
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

	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MinuteText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SecondsText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BreakText;
	
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* TimerBox;

	UPROPERTY(EditAnywhere, Category = "Score")
	int MaxScore;

	UFUNCTION()
	void SetHealthBar(float percentage);

	UFUNCTION()
	void SetScoreText(int amount);

	UFUNCTION()
	bool TargetScoreReached();

	UFUNCTION()
	FText GetSeconds();

	UFUNCTION()
	FText GetMinutes();

private:

	int UIScore;

};
