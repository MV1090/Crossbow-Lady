// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyController.h"
#include "Enemy/BaseEnemy.h"

AEnemyController::AEnemyController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AEnemyController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	ABaseEnemy* BaseEnemy = Cast<ABaseEnemy>(pawn);
	if (BaseEnemy)
	{
		if (BaseEnemy->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(BaseEnemy->BehaviorTree->BlackboardAsset));
			BehaviorComp->StartTree(*BaseEnemy->BehaviorTree);
		}
	}
}

void AEnemyController::SetSeenTarget(AActor* pawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject("Target", pawn);
	}
}

void AEnemyController::ResetTarget()
{
	if (BlackboardComp)
	{		
		BlackboardComp->SetValueAsObject("Target", nullptr);
		
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Stop looking at play")));
	}
}

void AEnemyController::SetDestination(FVector destination)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector("NextPos", destination);
	}
}

void AEnemyController::SetCanSeePlayer(bool SeePlayer, UObject* Player)
{
	UBlackboardComponent* bb = GetBlackboardComponent();
	bb->SetValueAsBool(FName("Can See Player"), SeePlayer);
	if (SeePlayer) {
		bb->SetValueAsObject(FName("Player Target"), Player);
	}
}
