/**
* @class APlayer_Character
 * @brief This base class is intended for interactive interaction with objects in the world like "buttons, levers, etc."
 * - it also contains a Delegate to support the integration of other systems that will call this class 
 *
 * @date September 2024
 * @copyright (c) 2024 sllikk Inc. All rights reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player_Character.generated.h"

class USkeletalMeshComponent;
class ABase_PlayerController;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS(Blueprintable)
class AI_CORE_API APlayer_Character : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkeletalMesh", meta=(AllowPrivateAccess = "true"))
	USkeletalMeshComponent* pMesh1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(AllowPrivateAccess = "true"))
	UCameraComponent* pCameraComponent;

#pragma region Input

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pMoveAction;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pJumpAction;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pLookAction;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pInteractAction;
	
	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* pDefaultInputMapping;
	
#pragma endregion 	

public:
	// Sets default values for this character's properties
	explicit APlayer_Character(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable, meta=(AllowPrivateAccess = "true"))
	bool bHasWeapon;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);
	void Interact();
	
public:	

	bool GetHasWeapon() const;
	void SetHasWeapon(bool blsweapon);
	UCameraComponent* GetCameraComponent() const;
};


FORCEINLINE bool APlayer_Character::GetHasWeapon() const
{
	return bHasWeapon;
}

FORCEINLINE void APlayer_Character::SetHasWeapon(bool blsweapon)
{
	bHasWeapon = blsweapon;
}

FORCEINLINE UCameraComponent* APlayer_Character::GetCameraComponent() const
{
	return pCameraComponent;
}

