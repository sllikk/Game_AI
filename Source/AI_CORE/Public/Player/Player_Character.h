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

		/* Forward Declared for optimization compiling*/
class USkeletalMeshComponent;
class ABase_PlayerController;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class UFlashLight_Component;
struct FInputActionValue;


UCLASS(Blueprintable, Config=Game)
class AI_CORE_API APlayer_Character : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkeletalMesh", meta=(AllowPrivateAccess = "true"))
	USkeletalMeshComponent* pMesh1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(AllowPrivateAccess = "true"))
	UCameraComponent* pCameraComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(AllowPrivateAccess = "true"))
	UFlashLight_Component* pFlashLight_Component = nullptr;
	
#pragma region Input

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pMoveAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pJumpAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pCrouchAction = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pLookAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pInteractAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pPhysicsGrabAction = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputAction* pFleshLightAction = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* pDefaultInputMapping = nullptr;
	
#pragma endregion 	

public:
	// Sets default values for this character's properties
	explicit APlayer_Character(const FObjectInitializer& ObjectInitializer);

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;

	/* Input Func */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);
	void Interact();

	//GamePlay func
	bool RestoreHealth(float amount);
	bool RestoreSuitCharge(float amounth);
	void Restore_SuitEnergy();

public:	

	bool GetHasWeapon() const;
	int16 GetHealth() const;
	int16 GetMaxHealth() const;
	int16 GetMaxSuitCharge() const;
	int16 GetSuitCharge() const;
	float GetSuit_Energy() const;
	float GetMaxSuit_Energy() const;
	
	UCameraComponent* GetCameraComponent() const;
	USkeletalMeshComponent* GetMesh1P() const;
	
	void SetHasWeapon(bool blsweapon);


private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable, meta=(AllowPrivateAccess = "true"))
	bool bHasWeapon;
	UPROPERTY(Config)
	int16 m_imaxhealth;
	UPROPERTY(Config)
	int16 m_imaxsuit_charge;
	UPROPERTY(Config)		
	float m_flmaxsuit_energy;
	UPROPERTY(Config)		
	float m_flmax_raycast_lenght;	

	bool blsDead;
	
	int16 m_isuit_charge;	
	int16 m_ihealth;
	float m_flsuit_energy;
	
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

inline int16 APlayer_Character::GetHealth() const
{
	return m_ihealth;
}

inline int16 APlayer_Character::GetMaxHealth() const
{
	return m_imaxsuit_charge;
}

inline int16 APlayer_Character::GetSuitCharge() const
{
	return m_isuit_charge;
}

inline int16 APlayer_Character::GetMaxSuitCharge() const
{
	return m_imaxsuit_charge;	
}

inline USkeletalMeshComponent* APlayer_Character::GetMesh1P() const
{
	return pMesh1P;
}

inline float APlayer_Character::GetSuit_Energy() const
{
	return m_flsuit_energy;
}

inline float APlayer_Character::GetMaxSuit_Energy() const
{
	return m_flmaxsuit_energy;
}


