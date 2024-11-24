// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy/BTTask_Attack.h"
#include "Enemy/BaseEnemy.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIOwner = OwnerComp.GetAIOwner(); // to get the controller
	APawn* Enemy = AIOwner->GetPawn();
	ABaseEnemy* BaseEnemy = Cast<ABaseEnemy>(Enemy);

	if(!BaseEnemy)
		return EBTNodeResult::Failed;
			
	GetWorld()->SpawnActor<ABaseProjectile>(BaseEnemy->ProjectileClass, BaseEnemy->SpawnPoint->GetComponentLocation(), BaseEnemy->SpawnPoint->GetComponentRotation());
	
	return EBTNodeResult::Succeeded;
}
