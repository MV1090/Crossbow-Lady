// Fill out your copyright notice in the Description page of Project Settings.
#include "Enemy/TurretEnemy.h"


ATurretEnemy::ATurretEnemy()
{	
	MeshSetUp(Body, "Body", "/Engine/BasicShapes/Cone", FVector(15.0f, 0.0f, 0.0f), FVector(1.0f, 1.0f, 0.5f), FRotator(90.0f, -90.0f, 90.0f));	
}

void ATurretEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ATurretEnemy::OnSeePlayer);		
	}

	if (HealthComponent)
	{
		HealthComponent->Init(50.0f);
	}	
}

//void ATurretEnemy::ResetTarget()
//{	
//	AEnemyController* AIController = Cast<AEnemyController>(GetController());
//
//	if (AIController)
//	{
//		AIController->ResetTarget();
//	}
//}

void ATurretEnemy::OnSeePlayer(APawn* Pawn)
{
	AEnemyController* AIController = Cast<AEnemyController>(GetController());
	
	if (AIController)
	{	

		AFPSCharacter* player = Cast<AFPSCharacter>(Pawn);
		if (!player) return;

		AIController->SetCanSeePlayer(true, player);

		AIController->RunTriggerableTimer();
	}
}


