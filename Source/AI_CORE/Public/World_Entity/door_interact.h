// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "World_Entity/base_interact_actor.h"
#include "door_interact.generated.h"

class UStaticMeshComponent;
class UCurveFloat;
struct FTimeline;

UCLASS()
class AI_CORE_API Adoor_interact : public Abase_interact_actor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* pSM_Door;
	
	UPROPERTY(EditAnywhere, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* pSM_DoorFrame;

	UPROPERTY(EditAnywhere, Category="Curve")
	UCurveFloat* pCurveFloat;

	UPROPERTY()
	FTimeline Timeline;
	
public: 	

	explicit  Adoor_interact(const FObjectInitializer& Initializer);

protected:	

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void Player_Interact(AActor* Interacting_Player) override;
	
public:

	UFUNCTION()
	void OpenDoor(float Value);
	void OnSameSide();
	
	bool blsDoorClossed;
	float fl_rotateAngle;



};
