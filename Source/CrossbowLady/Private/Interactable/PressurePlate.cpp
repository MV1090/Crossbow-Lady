// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/PressurePlate.h"

// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));				
		CollisionComponent->SetBoxExtent(FVector(40.0f, 40.0f, 5.0f));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::BeginOverlap);
		RootComponent = CollisionComponent;
	}

	//Creating the Mesh outside this function made it accessible in the editor, not sure why?
	//MeshSetUp(Plate, "Pressure Plate", "/ Engine / VREditor / BasicMeshes / SM_Cube_01", "/Engine/VREditor/BasicMeshes/MI_Cube_03, FVector(0.0f, 0.0f, 1.9f), FVector(1.75f,1.75f,0.2f));
	
	if (!Plate)
	{
		Plate = CreateDefaultSubobject<UStaticMeshComponent>("Pressure Plate");
		Plate->SetupAttachment(RootComponent);
		Plate->BodyInstance.SetCollisionProfileName(TEXT("NoCollision"));

		ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Engine/VREditor/BasicMeshes/SM_Cube_01"));

		if (Asset.Succeeded())
		{
			Plate->SetStaticMesh(Asset.Object);
			Plate->SetRelativeLocation(FVector(0.0f, 0.0f, -6.0f));
			Plate->SetWorldScale3D(FVector(1.75f, 1.75f, 0.2f));
		}

		ConstructorHelpers::FObjectFinder<UMaterial>MeshMaterial(TEXT("/Engine/VREditor/BasicMeshes/MI_Cube_03"));
		if (MeshMaterial.Succeeded()) {
			PlateMaterialInstance = UMaterialInstanceDynamic::Create(MeshMaterial.Object, Plate);
		}

	    Plate->SetMaterial(0, PlateMaterialInstance);
	}

	if (!Base)
	{
		Base = CreateDefaultSubobject<UStaticMeshComponent>("Base");
		Base->SetupAttachment(RootComponent);
		Base->BodyInstance.SetCollisionProfileName(TEXT("NoCollision"));

		ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Engine/BasicShapes/Cube"));

		if (Asset.Succeeded())
		{
			Base->SetStaticMesh(Asset.Object);			
			Base->SetRelativeLocation(FVector(0.0f, 0.0f, -8.0f));
			Base->SetWorldScale3D(FVector(1.0f, 1.0f, 0.05f));
		}

		ConstructorHelpers::FObjectFinder<UMaterial>MeshMaterial(TEXT("/Engine/MapTemplates/Sky/M_BlackBackground"));
		if (MeshMaterial.Succeeded()) {
			BaseMaterialInstance = UMaterialInstanceDynamic::Create(MeshMaterial.Object, Base);
		}

		Base->SetMaterial(0, BaseMaterialInstance);		
	}	
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlate::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Cast<AFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter()))
	{
		LinkedGate->OpenDoor();
	}
}

//void APressurePlate::MeshSetUp(UStaticMeshComponent* mesh, FString viewportName, FString meshToSpawn, FString material, FVector location, FVector scale)
//{
//	mesh = CreateDefaultSubobject<UStaticMeshComponent>(*viewportName);
//	mesh->SetupAttachment(RootComponent);
//	mesh->BodyInstance.SetCollisionProfileName(TEXT("NoCollision"));
//
//	ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(*meshToSpawn);
//
//	if (Asset.Succeeded())
//	{
//		mesh->SetStaticMesh(Asset.Object);
//		mesh->SetRelativeLocation(FVector(location));
//		mesh->SetWorldScale3D(FVector(scale));
//	}
//
//	/*ConstructorHelpers::FObjectFinder<UMaterial>MeshMaterial(*material);
//	if (MeshMaterial.Succeeded()) {
//		MaterialInstance = UMaterialInstanceDynamic::Create(MeshMaterial.Object, mesh);
//	}
//
//	mesh->SetMaterial(0, MaterialInstance);*/
//}

