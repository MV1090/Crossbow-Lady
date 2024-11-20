// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/BaseCollectible.h"

// Sets default values
ABaseCollectible::ABaseCollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABaseCollectible::BeginOverlap);
		CollisionComponent->InitCapsuleSize(7.5f, 20.0f);
		RootComponent = CollisionComponent;
	}
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

void ABaseCollectible::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Cast<AFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter()))
	{
		OnCollect();
	}		
}

void ABaseCollectible::OnCollect()
{

}

