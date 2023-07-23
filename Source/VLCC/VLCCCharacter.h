// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "VLCCCharacter.generated.h"

UCLASS()
class VLCC_API AVLCCCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AVLCCCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* RestartAction;

	UFUNCTION()
	void OnAudioFinished();

protected:

	virtual void BeginPlay() override;

	virtual void Destroyed();

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Collect();

	void CallRestartPlayer();

private:

	UPROPERTY(VisibleAnywhere, Category = "Music")
	class UAudioComponent* BackgroundMusicAudioComponent;

	UPROPERTY(EditAnywhere, Category = "Music")
	USoundBase* BackgroundMusic;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	class ACollectableObject* CollectedItem;

	UPROPERTY(EditAnywhere, Category = "Collectibles")
	int32 NumberOfItems;

public:

	void SetCollectedItem(ACollectableObject* Item);

	FORCEINLINE int32 GetNumberOfItems() { return NumberOfItems; }

};
