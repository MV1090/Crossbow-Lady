// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseProjectile.h"
#include "CBLady.generated.h"

UCLASS()
class CROSSBOWLADY_API ACBLady : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACBLady();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TArray<TSubclassOf<class ABaseProjectile>> ProjectileClass;

	int projectileType = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	//UFUNCTION lets the function be blueprint accessible.
	UFUNCTION()
    void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Fire();
	
	UFUNCTION()
	void SetProjectileSlotOne();

	UFUNCTION()
	void SetProjectileSlotTwo();

	UFUNCTION()
	void SetProjectileSlotThree();


	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;	
};
