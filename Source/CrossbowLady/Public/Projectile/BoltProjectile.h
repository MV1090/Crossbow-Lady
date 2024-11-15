// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/BaseProjectile.h"
#include "BoltProjectile.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API ABoltProjectile : public ABaseProjectile
{
	GENERATED_BODY()
	
public: 

	virtual void ProjectileSetUP() override;
	
	virtual void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) override;

	ABoltProjectile();
};
