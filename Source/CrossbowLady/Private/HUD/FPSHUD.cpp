// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"

void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowGameMenu(GameWidget);
	//ShowMainMenu(MainMenuWidget);
	EndGameWidgetContainer = CreateWidget<UEndGameScreen>(GetWorld(), EndGameWidget);

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->SetIgnoreMoveInput(false);

}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AFPSHUD::ShowGameMenu(TSubclassOf<UGameHUDWidget> newGameWidget)
{
	if (gameWidgetContainer) {
		gameWidgetContainer->RemoveFromParent();
		gameWidgetContainer = nullptr;
	}

	if (newGameWidget) {
		gameWidgetContainer = CreateWidget<UGameHUDWidget>(GetWorld(), newGameWidget);
		gameWidgetContainer->AddToViewport();
	}
}

void AFPSHUD::ShowEndGame(FText endgameText)
{

	if (EndGameWidgetContainer) {
		EndGameWidgetContainer->AddToViewport();
		EndGameWidgetContainer->EndGameText->SetText(endgameText);
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0);
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		PlayerController->SetInputMode(FInputModeUIOnly());
		PlayerController->SetIgnoreMoveInput(true);
	}
}


