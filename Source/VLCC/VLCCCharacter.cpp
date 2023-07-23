// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCCCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CollectableObject.h"
#include "RespawnGameMode.h"
#include "VLCCPlayerController.h"

AVLCCCharacter::AVLCCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AVLCCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (const ULocalPlayer* Player = (GEngine && GetWorld()) ? GEngine->GetFirstGamePlayer(GetWorld()) : nullptr)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	if (AVLCCPlayerController* VLCCPlayerController = Cast<AVLCCPlayerController>(GetController()))
	{
		VLCCPlayerController->InitItems(NumberOfItems);
	}
}

void AVLCCCharacter::Destroyed()
{
	Super::Destroyed();

	if (UWorld* World = GetWorld())
	{
		if (ARespawnGameMode* GameMode = Cast<ARespawnGameMode>(World->GetAuthGameMode()))
		{
			GameMode->GetOnPlayerDied().Broadcast(this);
		}
	}
}


void AVLCCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVLCCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVLCCCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVLCCCharacter::Look);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AVLCCCharacter::Collect);

		EnhancedInputComponent->BindAction(RestartAction, ETriggerEvent::Triggered, this, &AVLCCCharacter::CallRestartPlayer);
	}
}

void AVLCCCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AVLCCCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void AVLCCCharacter::Collect()
{
	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(false);
		if (AVLCCPlayerController* VLCCPlayerController = Cast<AVLCCPlayerController>(GetController()))
		{
			VLCCPlayerController->UpdateHUDCollected(CollectedItem->GetIndex());
		}
		CollectedItem->Interact();
	}
}

void AVLCCCharacter::CallRestartPlayer()
{
	AController* CortollerRef = GetController();

	Destroy();

	if (UWorld* World = GetWorld())
	{
		if (ARespawnGameMode* GameMode = Cast<ARespawnGameMode>(World->GetAuthGameMode()))
		{
			GameMode->RestartPlayer(CortollerRef);
		}
	}
}

void AVLCCCharacter::SetCollectedItem(ACollectableObject* Item)
{
	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(false);
	}

	CollectedItem = Item;

	if (CollectedItem)
	{
		CollectedItem->ShowPickupWidget(true);
	}
}
