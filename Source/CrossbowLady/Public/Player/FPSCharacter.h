// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/StaticMesh.h"
#include "Projectile/BaseProjectile.h"
#include "Components/HealthComponent.h"
#include "FPSCharacter.generated.h"

UCLASS()
class CROSSBOWLADY_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void TakeDamage(float damage);

	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
	void StartJump();

    UFUNCTION()
	void StopJump();	

	UFUNCTION()
	void Fire();

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* Body;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* Hat; 

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class ABaseProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Health")
	float StartingHealth;

private:

	void MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn,  FVector location, FVector scale);

	UMaterial* StoredMaterial;

	UMaterialInstanceDynamic* DynamicMaterialInst;
};
