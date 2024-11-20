// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!HealthComponent)
	{
		HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	}

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseEnemy::MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FVector location, FVector scale, FRotator rotation)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*viewportName);
	mesh->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(*meshToSpawn);

	if (Asset.Succeeded())
	{
		mesh->SetStaticMesh(Asset.Object);
		mesh->SetRelativeLocation(FVector(location));
		mesh->SetWorldScale3D(FVector(scale));
		mesh->SetRelativeRotation(FRotator(rotation));
	}
}

void ABaseEnemy::OnTakeDamage(float Damage)
{
	HealthComponent->Damage(Damage);

	if (HealthComponent->IsDead())
		Destroy();

}

// Called to bind functionality to input
//void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

