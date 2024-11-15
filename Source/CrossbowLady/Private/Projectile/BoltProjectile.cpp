// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile/BoltProjectile.h"

void ABoltProjectile::ProjectileSetUP()
{
    Super::ProjectileSetUP();

    if (ProjectileMeshComponent)
    {
        if (CollisionComponent) {
            CollisionComponent->InitSphereRadius(5.0f);

            static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("/Game/Mesh/SM_Arrow.SM_Arrow"));
            if (SphereMeshAsset.Succeeded()) {
                ProjectileMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
            }

            /*  static ConstructorHelpers::FObjectFinder<UMaterial>SphereMaterial(TEXT("/Game/Material/M_Projectile.M_Projectile"));
              if (SphereMaterial.Succeeded()) {
                  ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(SphereMaterial.Object, ProjectileMeshComponent);
              }*/

              // ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
              // ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
            ProjectileMeshComponent->SetupAttachment(RootComponent);
            ProjectileMeshComponent->SetRelativeLocation(FVector(-60.0f, 0.0f, 0.0f));
            ProjectileMeshComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
        }
    }
    InitialLifeSpan = 3.0f;
}

void ABoltProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

}


ABoltProjectile::ABoltProjectile()
{
    ProjectileSetUP();
}
