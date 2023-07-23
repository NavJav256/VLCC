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
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Collectibles")
	TArray<bool> CollectedItems;
};
