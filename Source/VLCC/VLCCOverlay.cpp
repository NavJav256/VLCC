// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCCOverlay.h"
#include "Components/TextBlock.h"

void UVLCCOverlay::SetCollected(int32 NumCollected, int32 Total)
{
	if (CollectedText)
	{
		FString CText = FString::Printf(TEXT("%d / %d"), NumCollected, Total);
		CollectedText->SetText(FText::FromString(CText));
	}
}
