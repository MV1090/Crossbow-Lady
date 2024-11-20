// Fill out your copyright notice in the Description page of Project Settings.
#include "Collectible/HealthPickUp.h"

AHealthPickUp::AHealthPickUp()
{
	MeshSetUp(LowerBody, "LowerBody", "/Engine/BasicShapes/Cylinder", FVector(0.0f, 0.0f, -5.0f), FVector(0.12f, 0.12f, 0.3f));
	MeshSetUp(Lid, "Lid", "/Engine/BasicShapes/Cylinder", FVector(0.0f, 0.0f, 14.0f), FVector(0.075f, 0.075f, 0.05f));
	MeshSetUp(UpperBody, "UpperBody", "/Engine/BasicShapes/Sphere", FVector(0.0f, 0.0f, 10.0f), FVector(0.12f, 0.12f, 0.1f));		
}

void AHealthPickUp::BeginPlay()
{
	Super::BeginPlay();
}

void AHealthPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealthPickUp::OnCollect()
{
	Super::OnCollect();

	AFPSCharacter* player = Cast<AFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	if (player)
	{
		player->HealthComponent->Heal(HealthToAdd);

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), player->HealthComponent->GetHealth()));
	}
	Destroy();
}

void AHealthPickUp::MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FVector location, FVector scale)
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*viewportName);
	mesh->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(*meshToSpawn);

	if (Asset.Succeeded())
	{
		mesh->SetStaticMesh(Asset.Object);
		mesh->SetRelativeLocation(FVector(location));
		mesh->SetWorldScale3D(FVector(scale));
	}
}
