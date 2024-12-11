// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Components/BackgroundBlur.h"
#include "GUI/RestartButtonWidget.h"
#include "GUI/QuitButtonWidget.h"
#include "Components/VerticalBox.h"
#include "Blueprint/UserWidget.h"
#include "EndGameScreen.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UEndGameScreen : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* EndGameText;

	UPROPERTY(meta = (BindWidget))
	UBackgroundBlur* BackgroundBlur;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ButtonContainer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class URestartButtonWidget> RestartButton;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UQuitButtonWidget> QuitButton;

	void SetEndGameText(FText text);

private:

};
