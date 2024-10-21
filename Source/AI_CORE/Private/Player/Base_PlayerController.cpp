// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Base_PlayerController.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Debug_Entity/Base_CheatManager.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "World_Entity/Interact_Interface.h"

ABase_PlayerController::ABase_PlayerController()
{
	CheatClass = UBase_CheatManager::StaticClass();
}

void ABase_PlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void ABase_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void ABase_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}
