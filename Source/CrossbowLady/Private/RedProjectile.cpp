// Fill out your copyright notice in the Description page of Project Settings.


#include "RedProjectile.h"

ARedProjectile::ARedProjectile() 
{
	BulletSpeed = 2500;
	ProjectileMovementComponent->InitialSpeed = BulletSpeed;
	ProjectileMovementComponent->MaxSpeed = BulletSpeed;

		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/Materials/M_RedMaterial.M_RedMaterial'"));
		if (Material.Succeeded())
		{
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
		}
		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);		


}