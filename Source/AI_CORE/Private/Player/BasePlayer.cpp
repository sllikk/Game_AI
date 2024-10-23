// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/BasePlayer.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Components/CapsuleComponent.h"
#include "World_Entity/Interact_Interface.h"

ABasePlayer::ABasePlayer(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.Get())
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Player_CameraComponent"));
	//pCameraComponent->SetupAttachment(GetCapsuleComponent());
	pCameraComponent->SetRelativeLocation(FVector(0.f, 30.f, 80.f)); // Position the camera	
	pCameraComponent->SetRelativeRotation(FRotator(0.f, 0.f, 90.f)); // Position the camera	
	pCameraComponent->bUsePawnControlRotation = true;
	
	pMesh1P = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Player_SkeletalMeshComponent"));
	pMesh1P->SetOnlyOwnerSee(false);
	pMesh1P->SetupAttachment(pCameraComponent);
	pMesh1P->SetRelativeRotation(FRotator(2.0f, -15.0f, 5.0f));
	pMesh1P->SetRelativeLocation(FVector(0, 0, -160.0f));
	pMesh1P->CastShadow = false;

	m_ihealth = m_imaxhealth;
	m_isuit_charge = m_imaxsuit_charge;
	m_flsuit_energy = m_flmaxsuit_energy;
	
	
}


// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* P_Controller = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(P_Controller->GetLocalPlayer()))
		{
			LocalPlayerSubsystem->AddMappingContext(pDefaultInputMapping, 0);
		}	
	}

}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(pMoveAction, ETriggerEvent::Triggered, this, &ABasePlayer::MoveInput);
		EnhancedInputComponent->BindAction(pLookAction, ETriggerEvent::Triggered, this, &ABasePlayer::LookInput);
		EnhancedInputComponent->BindAction(pInteractAction, ETriggerEvent::Started, this, &ABasePlayer::Interact);
	}
	
}

void ABasePlayer::MoveInput(const FInputActionValue& Value)
{
	FVector2d MoveValue = Value.Get<FVector2d>();

	AddMovementInput(GetActorForwardVector(), MoveValue.Y);
	AddMovementInput(GetActorRightVector(), MoveValue.X);
	
}

void ABasePlayer::LookInput(const FInputActionValue& Value)
{
	FVector2d LookValue = Value.Get<FVector2d>();

	AddControllerYawInput(LookValue.X);
	AddControllerPitchInput(LookValue.Y);
}

void ABasePlayer::Interact()
{
	FHitResult Interact_Result;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	const FVector& Start = pCameraComponent->GetComponentLocation();
	const FVector& End = Start + (pCameraComponent->GetForwardVector() * m_flmax_raycast_lenght);

	if (GetWorld()->SweepSingleByChannel(Interact_Result, Start, End, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(15.0f), QueryParams))
	{
		AActor* Hit_Entity = Interact_Result.GetActor();
		if (Hit_Entity != nullptr && Hit_Entity->GetClass()->ImplementsInterface(UInteract_Interface::StaticClass()))
		{
			DrawDebugSphere(GetWorld(), Interact_Result.Location, 15, 20, FColor::Cyan, false, 0.3f);

			if (IInteract_Interface* Interact_Interface = Cast<IInteract_Interface>(Hit_Entity))
			{
				Interact_Interface->Player_Interact(this);
			}
		}
	}
}

bool ABasePlayer::RestoreHealth(float amount)
{
	return false;
	
}

bool ABasePlayer::RestoreSuitCharge(float amounth)
{
	return false;
	
}

void ABasePlayer::Restore_SuitEnergy()
{

}


