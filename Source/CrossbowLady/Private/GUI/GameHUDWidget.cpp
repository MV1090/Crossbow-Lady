// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameHUDWidget.h"

void UGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetHealthBar(1.0f);
	SetScoreText(0);
}

void UGameHUDWidget::SetHealthBar(float percentage)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(percentage);
}

void UGameHUDWidget::SetScoreText(int amount)
{
	if (!ScoreText) return;

	UIScore += amount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
