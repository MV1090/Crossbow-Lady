// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ButtonWidget.h"

void UButtonWidget::SetText(FString value)
{
	ButtonText->SetText(FText::FromString(value));	
}

void UButtonWidget::ActivateButton()
{
	Button->OnClicked.AddDynamic(this, &UButtonWidget::OnClicked);
}

void UButtonWidget::OnClicked()
{

}

