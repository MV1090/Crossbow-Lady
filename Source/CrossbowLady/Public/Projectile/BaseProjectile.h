// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "BaseProjectile.generated.h"

UCLASS()
class CROSSBOWLADY_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UMaterialInstanceDynamic* ProjectileMaterialInstance;

	UFUNCTION()
	void FireInDirection(const FVector& ShootDirection);

	UFUNCTION()
	virtual void OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void ProjectileSetUP();

private:

	
};
