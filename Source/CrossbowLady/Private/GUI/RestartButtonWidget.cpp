// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/RestartButtonWidget.h"

void URestartButtonWidget::NativeConstruct()
{
   
}

void URestartButtonWidget::OnClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("FPSGameMap"));
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Level open")));
}


