// Fill out your copyright notice in the Description page of Project Settings.
#include "Projectile/EnemyBallProjectile.h"
#include "Player/FPSCharacter.h"

AEnemyBallProjectile::AEnemyBallProjectile()
{
    ProjectileSetUP();
}

void AEnemyBallProjectile::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyBallProjectile::ProjectileSetUP()
{
    Super::ProjectileSetUP();

    if (CollisionComponent) {
        CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBallProjectile::OnProjectileOverlap);
        CollisionComponent->InitSphereRadius(20.0f);
    }

    if (ProjectileMeshComponent)
    {
        ConstructorHelpers::FObjectFinder<UStaticMesh>BallMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));
        if (BallMeshAsset.Succeeded()) {
            ProjectileMeshComponent->SetStaticMesh(BallMeshAsset.Object);
            ProjectileMeshComponent->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
        }

        ConstructorHelpers::FObjectFinder<UMaterial>BallMaterial(TEXT("/Game/Projectile/M_Ball"));
        if (BallMaterial.Succeeded()) {
            ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(BallMaterial.Object, ProjectileMeshComponent);
        }

        ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);

        ProjectileMeshComponent->SetupAttachment(RootComponent);    
    }

    if (ProjectileMovementComponent)
    {
        ProjectileMovementComponent->InitialSpeed = BulletSpeed;
        ProjectileMovementComponent->MaxSpeed = BulletSpeed;
        ProjectileMovementComponent->Bounciness = BounceValue;
        ProjectileMovementComponent->ProjectileGravityScale = GravityScale;
    }
    InitialLifeSpan = 3.0f;
}

void AEnemyBallProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnProjectileOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Hit")));       

   AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);

    if (player)
    {
        player->OnTakeDamage(10.0f);

        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), player->HealthComponent->GetHealth()));

        if (player->HealthComponent->GetHealth() <= 0)
            OtherActor->Destroy();

        Destroy();
    }
}
