// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public:

	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonText;

	UFUNCTION()
	void SetText(FString value);

	UFUNCTION()
	void ActivateButton();

	UFUNCTION()
	virtual void OnClicked();

};
