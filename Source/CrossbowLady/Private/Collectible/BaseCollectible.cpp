// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/BaseCollectible.h"

// Sets default values
ABaseCollectible::ABaseCollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

