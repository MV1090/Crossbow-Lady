// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacter.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;	

	if (!FPSCameraComponent) {
		FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
		FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
		FPSCameraComponent->SetRelativeLocation(FVector(30.0f, 0.0f, 50.0f));
		FPSCameraComponent->bUsePawnControlRotation = true;
	}
	/*
	FVector hatPos = FVector(-30.0f, 0.0f, 25.0f);
	FVector hatScale = FVector(1.0f, 1.0f, 0.5f);*/
	MeshSetUp(Hat, "Hat", "/Engine/BasicShapes/Cone", FVector(-30.0f, 0.0f, 25.0f), FVector(1.0f, 1.0f, 0.5f));
	
	/*FVector bodyPos = FVector(-30.0f, 0.0f, -60.0f);
	FVector bodyScale = FVector(0.5f, 0.5f, 1.4f)*/;
	MeshSetUp(Body, "Body", "/Engine/BasicShapes/Cylinder", FVector(-30.0f, 0.0f, -60.0f) , FVector(0.5f, 0.5f, 1.4f));
	
	if (!HealthComponent)
	{
		HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));		
	}
		
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	HealthComponent->Init(StartingHealth);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), HealthComponent->GetHealth()));
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::TakeDamage(float damage)
{
	HealthComponent->Damage(damage);
}

void AFPSCharacter::MoveForward(float value)
{
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);
}

void AFPSCharacter::MoveRight(float value)
{
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;

	TakeDamage(10.0f);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), HealthComponent->GetHealth()));
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Fire()
{
	if (!ProjectileClass) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

	FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

	FRotator MuzzleRotation = CameraRotation;
	//MuzzleRotation.Pitch += 10.0f;

	// Unity Instantiate
	// 1. Get World we to spawn in
	// 2. Spawn Actor with parameters to setup
	UWorld* World = GetWorld();
	if (!World) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	if (!Projectile) return;

	FVector LaunchDirection = MuzzleRotation.Vector();
	Projectile->FireInDirection(LaunchDirection);
}

void AFPSCharacter::MeshSetUp(UStaticMeshComponent* mesh, FString viewportName,FString meshToSpawn, FVector location, FVector scale)
{		
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*viewportName);
	mesh->SetupAttachment(FPSCameraComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(*meshToSpawn);

	if (Asset.Succeeded())
	{
		mesh->SetStaticMesh(Asset.Object);
		mesh->SetRelativeLocation(FVector(location));
		mesh->SetWorldScale3D(FVector(scale));
	}
}

