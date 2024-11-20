// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/TurretEnemy.h"

ATurretEnemy::ATurretEnemy()
{	
	MeshSetUp(Body, "Body", "/Engine/BasicShapes/Cone", FVector(15.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 0.5f), FRotator(90.0f, -90.0f, 90.0f));
}
