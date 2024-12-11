// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/EndGameScreen.h"

void UEndGameScreen::NativeConstruct()
{
	Super::NativeConstruct();

	UUserWidget* restart = CreateWidget(this, RestartButton);
	ButtonContainer->AddChildToVerticalBox(restart);

	URestartButtonWidget* restartButton = Cast<URestartButtonWidget>(restart);
	restartButton->SetText("Restart");
	restartButton->ActivateButton();

	UUserWidget* quit = CreateWidget(this, QuitButton);
	ButtonContainer->AddChildToVerticalBox(quit);

	UQuitButtonWidget* quitButton = Cast<UQuitButtonWidget>(quit);
	quitButton->SetText("Quit");
	quitButton->ActivateButton();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
	}
}

void UEndGameScreen::SetEndGameText(FText text)
{
	EndGameText->SetText(text);
}
