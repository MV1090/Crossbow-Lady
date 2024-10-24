// Fill out your copyright notice in the Description page of Project Settings.


#include "CBLady.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACBLady::ACBLady()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->JumpZVelocity = 600.f;

	if (!FPSCameraComponent) {
		// Create a first person camera component.
		FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
		

		// Attach the camera component to our capsule component.
		FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

		// Position the camera slightly above the eyes.
		FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

		// Enable the pawn to control camera rotation.
		FPSCameraComponent->bUsePawnControlRotation = true;
	}

	// Create a first person mesh component for the owning player.
	if (!FPSMesh) {
		FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));

		// Only the owning player sees this mesh.
		FPSMesh->SetOnlyOwnerSee(true);

		// Attach the FPS mesh to the FPS camera.
		FPSMesh->SetupAttachment(FPSCameraComponent);

		// Disable some environmental shadows to preserve the illusion of having a single mesh.
		FPSMesh->bCastDynamicShadow = false;
		FPSMesh->CastShadow = false;
	}
		
	// The owning player doesn't see the regular (third-person) body mesh.
	GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void ACBLady::BeginPlay()
{
	Super::BeginPlay();
	
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("Crossbow Lady has entered the party"));
}

// Called every frame
void ACBLady::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACBLady::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACBLady::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACBLady::MoveRight);

	
	PlayerInputComponent->BindAxis("Turn", this, &ACBLady::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ACBLady::AddControllerPitchInput);

	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACBLady::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACBLady::StopJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ACBLady::Fire);

	PlayerInputComponent->BindAction("SwapToProjectile1", IE_Pressed, this, &ACBLady::SetProjectileSlotOne);
	PlayerInputComponent->BindAction("SwapToProjectile2", IE_Pressed, this, &ACBLady::SetProjectileSlotTwo);
	PlayerInputComponent->BindAction("SwapToProjectile3", IE_Pressed, this, &ACBLady::SetProjectileSlotThree);
}

void ACBLady::MoveForward(float value)
{
	//FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	FVector direction = GetActorForwardVector();
	AddMovementInput(direction, value);
}

void ACBLady::MoveRight(float value)
{
	//2 ways to do the same thing.
	//FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	FVector direction = GetActorRightVector();
	AddMovementInput(direction, value);
}

void ACBLady::StartJump()
{
	bPressedJump = true;
}

void ACBLady::StopJump()
{
	bPressedJump = false;
}

void ACBLady::Fire()
{
	if (ProjectileClass[projectileType])
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			ABaseProjectile* Projectile = World->SpawnActor<ABaseProjectile>(ProjectileClass[projectileType], MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Firing"));

	UE_LOG(LogTemp, Warning, TEXT("Firing"));
}

void ACBLady::SetProjectileSlotOne()
{
	projectileType = 0;
}

void ACBLady::SetProjectileSlotTwo()
{
	projectileType = 1;
}

void ACBLady::SetProjectileSlotThree()
{
	projectileType = 2;
}

