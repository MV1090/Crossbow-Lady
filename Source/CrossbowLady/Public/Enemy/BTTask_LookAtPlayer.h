// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_LookAtPlayer.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API UBTTask_LookAtPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:


	FVector PlayerLocation;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
