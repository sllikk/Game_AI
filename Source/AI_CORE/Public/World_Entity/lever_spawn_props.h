// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "World_Entity/base_interact_actor.h"
#include "lever_spawn_props.generated.h"

struct FTimeline;
class UCurveFloat;
class AActor;
class UStaticMeshComponent;
class APlayer_Character;
class UBoxComponent;

UCLASS(Blueprintable)
class AI_CORE_API Alever_spawn_props : public Abase_interact_actor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Lever;

	UPROPERTY(EditAnywhere, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Button;

	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditAnywhere, Category="Spawn")
	UBoxComponent* Spawner_Box;
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	int32 MaxCountSpawn;


	
public:	

	explicit Alever_spawn_props(const FObjectInitializer& Initializer);
	
protected:	

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
  
	virtual bool CanInteract(AActor* Interacting_Player) override;
	virtual void ActivateInteract() override;
	virtual void EndInteract() override;
	virtual void ToggleState() override;

public:

	UPROPERTY(EditAnywhere, Category="Curve")
	UCurveFloat* pButtonCurveFloat;

	UFUNCTION()
	void PressButton(float Value);
	void ReleasedButton();
	
	bool blsButton_Pressed;
	bool blsSpawn_Props;
	
	FTimeline Timeline;
	FTimerHandle ButtonTimer;
	
	float ReleasedButtonZ;
	float PressedButtonZ;

	
};


