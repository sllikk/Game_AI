// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/Player_Character.h"
#include "UObject/Interface.h"
#include "Interact_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteract_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AI_CORE_API IInteract_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Player_Interact(AActor* Interacting_Player) = 0;
	virtual bool CanInteract(AActor* Interacting_Player) = 0;
	virtual void EndInteract() = 0;
	virtual void ActivateInteract() = 0;
	virtual void ToggleState() = 0;
	
	

	/*	
	// Function to interact with the object
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	bool Player_Interact(AActor* Interacting_Player);

	// Check if interaction is possible
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	bool CanInteract(AActor* Interacting_Player) const;

	// End interaction
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	bool EndInteract(AActor* Interacting_Player);

	// Activate interaction
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	bool ActivateInteract(AActor* Interacting_Player);

	// Switching the state of the object (for example, on/off)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	void ToggleState();

	// Description of the interaction (to display to the player)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)	
	FString GetDescriptionInteract() const;
	
	*/
	
};
