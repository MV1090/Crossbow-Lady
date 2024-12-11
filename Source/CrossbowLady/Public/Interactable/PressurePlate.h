// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Interactable/Gate.h"
#include "Player/FPSCharacter.h"
#include "GameFramework/Actor.h"
#include "PressurePlate.generated.h"

UCLASS()
class CROSSBOWLADY_API APressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlate();

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Base;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Plate;

	UPROPERTY(VisibleDefaultsOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Plate")
	UMaterialInstanceDynamic* BaseMaterialInstance;

	UPROPERTY(VisibleDefaultsOnly, Category = "Plate")
	UMaterialInstanceDynamic* PlateMaterialInstance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Gate")
	AGate* LinkedGate;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	//void MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FString material, FVector location, FVector scale);

	bool IsActive;	
};
