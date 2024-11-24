// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/BaseProjectile.h"
#include "EnemyBallProjectile.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AEnemyBallProjectile : public ABaseProjectile
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	
	AEnemyBallProjectile();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float BulletSpeed = 3000;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float GravityScale = 0.25;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float BounceValue = 0;

	virtual void ProjectileSetUP() override;

	virtual void OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
