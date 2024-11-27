// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile/BoltProjectile.h"


void ABoltProjectile::ProjectileSetUP()
{
    Super::ProjectileSetUP();

    if (CollisionComponent) {
        CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoltProjectile::OnProjectileOverlap);
        CollisionComponent->InitSphereRadius(5.0f);
    }

    if (ProjectileMeshComponent)
    {       
            ConstructorHelpers::FObjectFinder<UStaticMesh>BoltMeshAsset(TEXT("/Game/Mesh/SM_Arrow.SM_Arrow"));
            if (BoltMeshAsset.Succeeded()) {
                ProjectileMeshComponent->SetStaticMesh(BoltMeshAsset.Object);            
            }

            ConstructorHelpers::FObjectFinder<UMaterial>BoltMaterial(TEXT("/Game/Projectile/M_Bolt.M_Bolt"));
            if (BoltMaterial.Succeeded()) {
                ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(BoltMaterial.Object, ProjectileMeshComponent);
            }

            ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
          
            ProjectileMeshComponent->SetupAttachment(RootComponent);
            ProjectileMeshComponent->SetRelativeLocation(FVector(-60.0f, 0.0f, 0.0f));
            ProjectileMeshComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
            
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

void ABoltProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnProjectileOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);     

    ABaseEnemy* enemy = Cast<ABaseEnemy>(OtherActor);

    ATargetEnemy* target = Cast<ATargetEnemy>(OtherActor);      

    if(enemy)
    {       
        enemy->OnTakeDamage(10.0f);
        
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), enemy->HealthComponent->GetHealth()));

        if (enemy->HealthComponent->GetHealth()<= 0)
            OtherActor->Destroy();
    }    

    if (target)
    {
        AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
        if (!HUD) return;

        HUD->gameWidgetContainer->SetScoreText(target->Points);

        OtherActor->Destroy();
    }

}

ABoltProjectile::ABoltProjectile()
{
    ProjectileSetUP();
}
