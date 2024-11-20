// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Enemy/BaseEnemy.h"
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

protected:

public:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Body;

private:

};
