// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/BaseProjectile.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileSetUP();
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ProjectileMovementComponent->InitialSpeed * ShootDirection;
}

void ABaseProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	
	if (OtherActor != this)
	{
		ProjectileMovementComponent->StopMovementImmediately();
		ProjectileMovementComponent->ProjectileGravityScale = 0;

		AttachToActor(OtherActor, FAttachmentTransformRules::KeepWorldTransform);
	}
	
}

void ABaseProjectile::ProjectileSetUP()
{

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(15.0f);
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));		
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::OnProjectileOverlap);
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;	
		ProjectileMovementComponent->bShouldBounce = true;	
	}

	if (!ProjectileMeshComponent) 
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
	}

}


