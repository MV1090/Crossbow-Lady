// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GUI/ButtonWidget.h"
#include "Kismet/GameplayStatics.h"
#include "QuitButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UQuitButtonWidget : public UButtonWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual void OnClicked() override;
	
};
