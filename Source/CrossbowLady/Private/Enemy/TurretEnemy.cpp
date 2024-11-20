// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy/TurretEnemy.h"


ATurretEnemy::ATurretEnemy()
{	
	MeshSetUp(Body, "Body", "/Engine/BasicShapes/Cone", FVector(15.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 0.5f), FRotator(90.0f, -90.0f, 90.0f));

	
}

void ATurretEnemy::BeginPlay()
{
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ATurretEnemy::OnSeePlayer);		
	}
}

void ATurretEnemy::ResetTarget()
{	
	AEnemyController* AIController = Cast<AEnemyController>(GetController());

	if (AIController)
	{
		AIController->ResetTarget();
	}
}

void ATurretEnemy::OnSeePlayer(APawn* Pawn)
{
	AEnemyController* AIController = Cast<AEnemyController>(GetController());

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Looking at player")));

	if (AIController)
	{
		AIController->SetSeenTarget(Pawn);

		GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &ATurretEnemy::ResetTarget, 2.0f, false);			
	}
}


