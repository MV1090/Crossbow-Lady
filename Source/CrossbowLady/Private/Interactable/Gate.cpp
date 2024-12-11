// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/Gate.h"

// Sets default values
AGate::AGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!Gate)
	{
		Gate = CreateDefaultSubobject<UStaticMeshComponent>("Gate Mesh");
		Gate->SetupAttachment(RootComponent);
		Gate->BodyInstance.SetCollisionProfileName(TEXT("NoCollision"));

		ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Game/Mesh/CastleWalls/Gate"));

		if (Asset.Succeeded())
		{
			Gate->SetStaticMesh(Asset.Object);
		}

		
	}
}

void AGate::OpenDoor()
{	
	CanOpen = true;	
}

// Called when the game starts or when spawned
void AGate::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = Gate->GetRelativeLocation();
	NewLocation = FVector(CurrentLocation.X - XMovementDistance, CurrentLocation.Y - YMovementDistance, CurrentLocation.Z - ZMovementDistance);
	CanOpen = false;
}

// Called every frame
void AGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanOpen)
	{
		DoorOpening(DeltaTime);
	}
}

void AGate::DoorOpening(float DeltaTime)
{
	Gate->SetRelativeLocation(FMath::VInterpTo(CurrentLocation, NewLocation, DeltaTime, MovementSpeed));
	CurrentLocation = Gate->GetRelativeLocation();
	if (CurrentLocation == NewLocation)
		CanOpen = false;
}

