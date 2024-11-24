// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyController.h"
#include "BTTask_RandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UBTTask_RandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	FVector RandomLocation;
	UNavigationSystemV1* NavArea;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
