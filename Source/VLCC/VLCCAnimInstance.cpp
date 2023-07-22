// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCCAnimInstance.h"
#include "VLCCCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UVLCCAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	VLCCCharacter = Cast<AVLCCCharacter>(TryGetPawnOwner());
}

void UVLCCAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (VLCCCharacter == nullptr) VLCCCharacter = Cast<AVLCCCharacter>(TryGetPawnOwner());

	if (VLCCCharacter == nullptr) return;

	FVector Velocity = VLCCCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = VLCCCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = VLCCCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
}
