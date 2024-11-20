// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Collectible/BaseCollectible.h"
#include "HealthPickUp.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOWLADY_API AHealthPickUp : public ABaseCollectible
{
	GENERATED_BODY()

public: 

	AHealthPickUp();

protected:
	
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* LowerBody;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* UpperBody;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* Lid;

	UPROPERTY(EditAnywhere)
	float HealthToAdd = 10;
	
private:

	void MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FVector location, FVector scale);
};
