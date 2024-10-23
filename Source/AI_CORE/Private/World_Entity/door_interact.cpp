// Fill out your copyright notice in the Description page of Project Settings.

#include "World_Entity/door_interact.h"

#include "Components/ArrowComponent.h"
#include "Curves/CurveFloat.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/ArrowComponent.h"

Adoor_interact::Adoor_interact(const FObjectInitializer& Initializer)
	: Super(Initializer.Get()), pSM_Door(nullptr), pSM_DoorFrame(nullptr), pCurveFloat(nullptr), 
	 fl_rotateAngle(90)
{
	PrimaryActorTick.bCanEverTick = true;
		
	pSM_Door = Initializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Door_Mesh"));
	GetArrowComponent()->SetupAttachment(pSM_Door);
	
	pSM_DoorFrame = Initializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("DoorFrame_Mesh"));

	pSM_Door->SetupAttachment(RootComponent);\
	pSM_DoorFrame->SetupAttachment(RootComponent);
	
}

void Adoor_interact::BeginPlay()
{
	Super::BeginPlay();
	
	FOnTimelineFloat TimelineFloat;
	TimelineFloat.BindDynamic(this, &Adoor_interact::OpenDoor);
	Timeline.AddInterpFloat(pCurveFloat, TimelineFloat);
}

void Adoor_interact::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	Timeline.TickTimeline(DeltaSeconds);
}

void Adoor_interact::Player_Interact(AActor* Interacting_Player)
{
//	Super::Player_Interact(Interacting_Player);

	if (blsDoorClossed)
	{
		OnSameSide();
		Timeline.PlayFromStart();	
	}
	else
	{
		Timeline.Reverse();
	}

	blsDoorClossed = !blsDoorClossed;

	
}

void Adoor_interact::OpenDoor(float Value)
{
	float Angle = blsActorOnSameSide ? -fl_rotateAngle : fl_rotateAngle;
	FRotator NewRotator = FRotator(0.0f, Angle * Value, 0.0f);
	pSM_Door->SetRelativeRotation(NewRotator);
}

void Adoor_interact::OnSameSide()
{
/*
	if (GetInteractingPlayer())
	{
		//const FVector& Forward = GetArrowComponent()->GetForwardVector();
		//FVector Direction = GetInteractingPlayer()->GetActorLocation() - GetActorLocation();
		//Direction.Normalize();

		blsActorOnSameSide = blsActorOnSameSide = (FVector::DotProduct(GetInteractingPlayer()->GetActorForwardVector(), GetActorForwardVector())) >= 0;
	}

*/
}

