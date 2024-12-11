// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GUI/ButtonWidget.h"
#include "Kismet/GameplayStatics.h"
#include "RestartButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API URestartButtonWidget : public UButtonWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	virtual void OnClicked() override;

	
};
