// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Base_PlayerController.h"
#include "Debug_Entity/Base_CheatManager.h"


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
