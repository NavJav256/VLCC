// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VLCCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VLCC_API AVLCCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	void SetHUDCollected();

	void UpdateHUDCollected(int32 Index);

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	class AVLCCHUD* VLCCHUD;

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	TArray<bool> CollectedItems;

public:

	FORCEINLINE void InitItems(int32 NumberOfItems) { CollectedItems.Init(false, NumberOfItems); };
};
