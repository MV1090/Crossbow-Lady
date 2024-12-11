// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Gate.generated.h"

UCLASS()
class CROSSBOWLADY_API AGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGate();

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Gate;

	UFUNCTION()
	void OpenDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float XMovementDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float YMovementDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float ZMovementDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float MovementSpeed;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void DoorOpening(float DeltaTime);
	FVector CurrentLocation;
	FVector NewLocation;
	bool CanOpen;
};
