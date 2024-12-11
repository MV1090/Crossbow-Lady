// Fill out your copyright notice in the Description page of Project Settings.

#include "GUI/GameHUDWidget.h"

void UGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetHealthBar(1.0f);
	SetScoreText(0);

	TimerBox->AddChildToHorizontalBox(MinuteText);
	TimerBox->AddChildToHorizontalBox(BreakText);
	TimerBox->AddChildToHorizontalBox(SecondsText);	
}

void UGameHUDWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);	

	SecondsText->SetText(GetSeconds());
	MinuteText->SetText(GetMinutes());
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
	ScoreText->SetText(FText::FromString("Targets: " + FString::FromInt(UIScore) + "/" + FString::FromInt(MaxScore)));
}

bool UGameHUDWidget::TargetScoreReached()
{
	if(UIScore != MaxScore)
	    return false;
	else
		return true;
}

FText UGameHUDWidget::GetSeconds()
{	
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());

	int Seconds = GameMode->Seconds;

	FString formattedString = FString::Printf(TEXT("%02d"), Seconds);
	FText formattedText = FText::FromString(formattedString);

	return formattedText;
}

FText UGameHUDWidget::GetMinutes()
{
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());

	int Minutes = GameMode->Minutes;


	FString formattedString = FString::Printf(TEXT("%02d"), Minutes);
	FText formattedText = FText::FromString(formattedString);


	return FText(formattedText);
}
