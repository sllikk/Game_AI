// Fill out your copyright notice in the Description page of Project Settings.

#include "World_Entity/base_interact_actor.h"
#include "Components/ArrowComponent.h"

DEFINE_LOG_CATEGORY(LogInteractActor)


Abase_interact_actor::Abase_interact_actor(const FObjectInitializer& Initializer)
	: Super(Initializer.Get()), pArrowComponent(nullptr), pPlayer_Character(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
	
	pArrowComponent = Initializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("ArrowComponent"));
	
}

// Called when the game starts or when spawned
void Abase_interact_actor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Abase_interact_actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void Abase_interact_actor::Player_Interact(AActor* PlayerActor)
{
	if (CanInteract(PlayerActor))
	{
		ToggleState();
		UE_LOG(LogTemp, Warning, TEXT("Interact"));
	}
	
}

bool Abase_interact_actor::CanInteract(AActor* Interacting_Player)
{
	if (!Interacting_Player)
	{
		return false;
	}

	const FVector& ForwardVector = pArrowComponent->GetForwardVector();
	FVector DirectionToPlayer = Interacting_Player->GetActorLocation() - GetActorLocation();
	DirectionToPlayer.Normalize();
	
	float DotProduct = FVector::DotProduct(ForwardVector, DirectionToPlayer);
	float distance = FVector::Dist(Interacting_Player->GetActorLocation(), GetActorLocation());
	
	UE_LOG(LogTemp, Warning, TEXT("Dot Product: %f"), DotProduct);
	//UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), distance);

	// Interact 90
//	blsActorOnSameSide = blsActorOnSameSide = (FVector::DotProduct(Interacting_Player->GetActorForwardVector(), GetActorForwardVector())) >=0;
	
	constexpr float Threshold = 0.5f; 
	if (DotProduct > Threshold && distance <= 150)
	{
		return true; 
	}

	return false; 
}

void Abase_interact_actor::ActivateInteract()
{

}

void Abase_interact_actor::EndInteract()
{
	
}

void Abase_interact_actor::ToggleState()
{

}
