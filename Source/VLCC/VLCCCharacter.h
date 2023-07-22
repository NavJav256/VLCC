// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "VLCCCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCollectible
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Collectibles")
	FString Name;

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	bool bCollected = false;
};

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

protected:

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Collect();

private:

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	class ACollectableObject* CollectedItem;

	UPROPERTY(EditAnywhere, Category = "Collectibles")
	TArray<FCollectible> Items;

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	TArray<ACollectableObject*> Collected;

public:

	void SetCollectedItem(ACollectableObject* Item);

};
