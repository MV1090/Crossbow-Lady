// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/MainMenu.h"
#include "Player/FPSCharacter.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	TitleText->SetText(FText::FromString("CROSSBOW LADY"));
	
	UUserWidget* restart = CreateWidget(this, RestartButton);
	ButtonContainer->AddChildToVerticalBox(restart);
	
	URestartButtonWidget* restartButton = Cast<URestartButtonWidget>(restart);
	restartButton->SetText("Start");
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

void UMainMenu::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);
	
}

