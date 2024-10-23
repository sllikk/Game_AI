/**
* @class Abase_interact_actor
 * @brief this is the player class that is responsible for representing our player in the world
 *
 * @date September 2024
 * @copyright (c) 2024 sllikk Inc. All rights reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "Interact_Interface.h"
#include "GameFramework/Actor.h"
#include "base_interact_actor.generated.h"
struct FTimeline;
class UCurveFloat;
class UArrowComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogInteractActor, All, Warning);

UCLASS()
class AI_CORE_API Abase_interact_actor : public AActor, public IInteract_Interface
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Arrow", meta=(AllowPrivateAccess = "true"))
	UArrowComponent* pArrowComponent;

	//UPROPERTY()
	//APlayer_Character* pPlayer_Character;

public:	
	// Sets default values for this actor's properties
	explicit Abase_interact_actor(const FObjectInitializer& Initializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Start Interact Interface */ 
	virtual void Player_Interact(AActor* PlayerActor) override;
	virtual bool CanInteract(AActor* Interacting_Player) override;
	virtual void ActivateInteract() override;
	virtual void EndInteract() override;
	virtual void ToggleState() override;
	/* End Interact Interface */ 

	bool blsActorOnSameSide;   // for dot product
	
public:	

	bool GetActorOnSameSide() const;
	UArrowComponent* GetArrowComponent() const;
	//APlayer_Character* GetInteractingPlayer() const;	
};

FORCEINLINE UArrowComponent* Abase_interact_actor::GetArrowComponent() const
{
	return pArrowComponent;
}

FORCEINLINE bool Abase_interact_actor::GetActorOnSameSide() const
{
	return blsActorOnSameSide;
}

//FORCEINLINE APlayer_Character* Abase_interact_actor::GetInteractingPlayer() const
//{
//	return pPlayer_Character;
//}

