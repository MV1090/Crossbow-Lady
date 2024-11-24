// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy/BTTask_RandomLocation.h"

EBTNodeResult::Type UBTTask_RandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (NavArea)
	{
		AEnemyController* AIController = Cast<AEnemyController>(OwnerComp.GetAIOwner());

		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), AIController->GetPawn()->GetActorLocation(), RandomLocation, 15000.0f);
	}
	else
		return EBTNodeResult::Failed;

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Random Patrol Location"), RandomLocation);

	return EBTNodeResult::Succeeded;
}
