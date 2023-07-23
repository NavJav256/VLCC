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

	void SetItemOneText(FString Text);

	void SetItemTwoText(FString Text);

	void SetItemThreeText(FString Text);

	void SetItemFourText(FString Text);

	void SetItemFiveText(FString Text);

	void SetItemSixText(FString Text);

private:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CollectedText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemOneText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemTwoText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemThreeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemFourText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemFiveText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemSixText;
};
