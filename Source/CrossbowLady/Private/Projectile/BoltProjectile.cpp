// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile/BoltProjectile.h"
#include "Enemy/BaseEnemy.h"

void ABoltProjectile::ProjectileSetUP()
{
    Super::ProjectileSetUP();

    if (ProjectileMeshComponent)
    {
        if (CollisionComponent) {
            CollisionComponent->InitSphereRadius(5.0f);

            static ConstructorHelpers::FObjectFinder<UStaticMesh>BoltMeshAsset(TEXT("/Game/Mesh/SM_Arrow.SM_Arrow"));
            if (BoltMeshAsset.Succeeded()) {
                ProjectileMeshComponent->SetStaticMesh(BoltMeshAsset.Object);            
            }

            static ConstructorHelpers::FObjectFinder<UMaterial>BoltMaterial(TEXT("/Game/Projectile/M_Bolt.M_Bolt"));
            if (BoltMaterial.Succeeded()) {
                ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(BoltMaterial.Object, ProjectileMeshComponent);
            }

            ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
          
            ProjectileMeshComponent->SetupAttachment(RootComponent);
            ProjectileMeshComponent->SetRelativeLocation(FVector(-60.0f, 0.0f, 0.0f));
            ProjectileMeshComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
        }

        ProjectileMovementComponent->InitialSpeed = BulletSpeed;
        ProjectileMovementComponent->MaxSpeed = BulletSpeed;
        ProjectileMovementComponent->Bounciness = BounceValue;
        ProjectileMovementComponent->ProjectileGravityScale = GravityScale;
    }

    InitialLifeSpan = 3.0f;
}

void ABoltProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnProjectileOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);     

    ABaseEnemy* enemy = Cast<ABaseEnemy>(OtherActor);

    if(enemy)
    {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Enemy Hit")));

        enemy->OnTakeDamage(10.0f);
    }
    
}

ABoltProjectile::ABoltProjectile()
{
    ProjectileSetUP();
}
