// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/TargetEnemy.h"

// Sets default values
ATargetEnemy::ATargetEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!TargetMesh)
	{
		TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Target Mesh"));
		ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Game/Target/Target.Target"));
		
		if (Asset.Succeeded())
		{
			TargetMesh->SetStaticMesh(Asset.Object);
		}
	}
}

// Called when the game starts or when spawned
void ATargetEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

