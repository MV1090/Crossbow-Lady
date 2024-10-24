// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueProjectile.h"

ABlueProjectile::ABlueProjectile()
{
	BulletSpeed = 500;
	ProjectileMovementComponent->InitialSpeed = BulletSpeed;
	ProjectileMovementComponent->MaxSpeed = BulletSpeed;
}