// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/QuitButtonWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void UQuitButtonWidget::NativeConstruct()
{
}

void UQuitButtonWidget::OnClicked()
{
    UWorld* World = GetWorld();
    if (World)
    {
        APlayerController* PlayerController = World->GetFirstPlayerController();
        if (PlayerController)
        {
            UKismetSystemLibrary::QuitGame(World, PlayerController, EQuitPreference::Quit, false);
        }
    }
}
