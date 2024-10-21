// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/Base_Game_Mod.h"

ABase_Game_Mod::ABase_Game_Mod()
{
	/* search debug controller */

//	static ConstructorHelpers::FClassFinder<APlayerController> FindController(TEXT("/Game/Blueprint/BP_Player_Debug_Controller"));
//	if (FindController.Succeeded()) {
//		PlayerControllerClass = FindController.Class;
//	}
	
	static ConstructorHelpers::FClassFinder<APlayerController> FindController(TEXT("/Game/Player/BP_Base_PlayerController"));
	if (FindController.Succeeded()) {
		PlayerControllerClass = FindController.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> FindPlayer(TEXT("/Game/Player/BP_Player_Character"));
	if (FindController.Succeeded()) {
		DefaultPawnClass = FindController.Class;
	}
}
