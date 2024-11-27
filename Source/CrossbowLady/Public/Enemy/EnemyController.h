// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AEnemyController : public AAIController
{
	GENERATED_BODY()
	
private:
	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

public:

	AEnemyController();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName BlackboardKey = "Target";

	virtual void OnPossess(APawn* pawn) override;

	void SetSeenTarget(AActor* pawn);

	void ResetTarget();

	void SetDestination(FVector destination);

	FTimerHandle RetriggerableTimerHandle;
	FTimerDelegate FunctionDelegate;
	void RunTriggerableTimer();

	UFUNCTION()
	void SetCanSeePlayer(bool SeePlayer, UObject* Player);
};
