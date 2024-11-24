// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/HealthComponent.h"
#include "Math/UnrealMath.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::Init(float maxHealth)
{
	MaxHealth = maxHealth;
	SetHealth(MaxHealth);
}

float UHealthComponent::GetHealth()
{
	return Health;
}

float UHealthComponent::GetNormalizedHealth()
{
	return FMath::Clamp(Health / MaxHealth, 0, 1);
}

void UHealthComponent::SetHealth(float newHealth)
{
	Health = FMath::Clamp(newHealth, 0, MaxHealth);
}

void UHealthComponent::Damage(float damage)
{
	if (damage > 0)
	{
		SetHealth(Health - damage);
	}		
}

void UHealthComponent::Heal(float healAmount)
{
	if (healAmount > 0)
	{
		SetHealth(Health + healAmount);
	}
}

bool UHealthComponent::IsDead()
{
	if(Health <= 0)
	    return true;

	else
		return false;
}

