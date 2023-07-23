// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VLCCOverlay.generated.h"

/**
 * 
 */
UCLASS()
class VLCC_API UVLCCOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetCollected(int32 NumCollected, int32 Total);

private:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CollectedText;
};
