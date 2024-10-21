// Fill out your copyright notice in the Description page of Project Settings.

#include "World_Entity/lever_spawn_props.h"

#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

Alever_spawn_props::Alever_spawn_props(const FObjectInitializer& Initializer)
	: Super(Initializer.Get()), SM_Lever(nullptr), SM_Button(nullptr), MaxCountSpawn(0), ReleasedButtonZ(1.0f), PressedButtonZ(-4.0f)
{
	SM_Lever = Initializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh_Lever"));
	RootComponent = SM_Lever;

	SM_Button = Initializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh_Button"));
	SM_Button->SetupAttachment(SM_Lever);
	GetArrowComponent()->SetupAttachment(SM_Lever);
	
	SM_Lever->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	SM_Button->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));

	Spawner_Box = Initializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Spawner_Box"));	
	
	
}

void Alever_spawn_props::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Timeline.TickTimeline(DeltaSeconds);

}

void Alever_spawn_props::BeginPlay()
{
	Super::BeginPlay();

	if (pButtonCurveFloat != nullptr)
	{
		FOnTimelineFloat TimelineFloat;
		TimelineFloat.BindDynamic(this, &Alever_spawn_props::PressButton);
		Timeline.AddInterpFloat(pButtonCurveFloat, TimelineFloat);
	}

}

bool Alever_spawn_props::CanInteract(AActor* Interacting_Player)
{
		return Super::CanInteract(Interacting_Player);
}

void Alever_spawn_props::ActivateInteract()
{
	Super::ActivateInteract();

	UWorld* World = GetWorld();

	if (World != nullptr)
	{
		FVector const& Origin = Spawner_Box->GetComponentLocation();
		FVector const& Extern = Spawner_Box->GetScaledBoxExtent();

		const FVector& SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extern);  

		AActor* SpawnActor = World->SpawnActor<AActor>(SpawnerClass, SpawnLocation, FRotator::ZeroRotator);

			if (SpawnActor != nullptr)
			{
				EndInteract();	
			}	
		}
	}


void Alever_spawn_props::EndInteract()
{
	Super::EndInteract();

}

void Alever_spawn_props::ToggleState()
{
	Super::ToggleState();

	Timeline.PlayFromStart();
	ActivateInteract();
}

void Alever_spawn_props::PressButton(float Value)
{
	float NewZ = FMath::Lerp(ReleasedButtonZ, PressedButtonZ, Value);

	FVector NewLocation = SM_Button->GetRelativeLocation();
	NewLocation.Z = NewZ;
	SM_Button->SetRelativeLocation(NewLocation);
	
	if (Value >= 1.0f)
	{
		GetWorldTimerManager().SetTimer(ButtonTimer, this ,&Alever_spawn_props::ReleasedButton, 0.2);
	}
	
}

void Alever_spawn_props::ReleasedButton()
{
	Timeline.Reverse();
}


