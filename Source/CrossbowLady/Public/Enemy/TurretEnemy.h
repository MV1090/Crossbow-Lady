// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Enemy/BaseEnemy.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Enemy/EnemyController.h"
#include "TurretEnemy.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API ATurretEnemy : public ABaseEnemy
{
	GENERATED_BODY()

public:

     ATurretEnemy();

	 virtual void BeginPlay() override;

protected:

public:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Body;

	UFUNCTION()
	void ResetTarget();

private:

	UFUNCTION()
	void OnSeePlayer(APawn* Pawn);

	//AEnemyController* AIController;

	FTimerHandle DelayHandle;

};
