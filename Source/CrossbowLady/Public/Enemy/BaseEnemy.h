// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Components/HealthComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/SceneComponent.h"
#include "BaseEnemy.generated.h"

UCLASS()
class CROSSBOWLADY_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FVector location = FVector(0.0f, 0.0f, 0.0f), FVector scale = FVector(0.0f, 0.0f, 0.0f), FRotator rotation = FRotator(0.0f, 0.0f, 0.0f));
		

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnTakeDamage(float Damage);
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere
		, Category = "Health")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UPawnSensingComponent* PawnSensingComp;


	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class ABaseProjectile> ProjectileClass;


	UPROPERTY(EditAnywhere, Category = "Projectile")
	USceneComponent* SpawnPoint;

private:

	
};
