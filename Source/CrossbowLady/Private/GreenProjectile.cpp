// Fill out your copyright notice in the Description page of Project Settings.


#include "GreenProjectile.h"


AGreenProjectile::AGreenProjectile() 
{
	BulletSpeed = 5000;
	ProjectileMovementComponent->InitialSpeed = BulletSpeed;
	ProjectileMovementComponent->MaxSpeed = BulletSpeed;

	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/Materials/M_GreenMaterial.M_GreenMaterial'"));
	if (Material.Succeeded())
	{
		ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
	}
	ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
}