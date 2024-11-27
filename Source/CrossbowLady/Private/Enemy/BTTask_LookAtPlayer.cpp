// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy/BTTask_LookAtPlayer.h"
#include "Enemy/BaseEnemy.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/FPSCharacter.h"

EBTNodeResult::Type UBTTask_LookAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIOwner = OwnerComp.GetAIOwner(); // to get the controller
	APawn* Enemy = AIOwner->GetPawn();
	ABaseEnemy* BaseEnemy = Cast<ABaseEnemy>(Enemy);

	if (!BaseEnemy)
		return EBTNodeResult::Failed;		

	PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	FVector forward = PlayerLocation - BaseEnemy->GetActorLocation();
	FVector worldUp = FVector::UpVector;

	FRotator Rot = UKismetMathLibrary::MakeRotFromXZ(forward, worldUp);

	BaseEnemy->SetActorRelativeRotation(Rot, true);	

	return EBTNodeResult::Succeeded;
}
