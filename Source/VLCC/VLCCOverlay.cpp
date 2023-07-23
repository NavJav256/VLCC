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

void UVLCCOverlay::SetItemOneText(FString Text)
{
	if (ItemOneText)
	{
		ItemOneText->SetText(FText::FromString(Text));
	}
}

void UVLCCOverlay::SetItemTwoText(FString Text)
{
	if(ItemTwoText)
	{
		ItemTwoText->SetText(FText::FromString(Text));
	}
}

void UVLCCOverlay::SetItemThreeText(FString Text)
{
	if(ItemThreeText)
	{
		ItemThreeText->SetText(FText::FromString(Text));
	}
}

void UVLCCOverlay::SetItemFourText(FString Text)
{
	if(ItemFourText)
	{
		ItemFourText->SetText(FText::FromString(Text));
	}
}

void UVLCCOverlay::SetItemFiveText(FString Text)
{
	if(ItemFiveText)
	{
		ItemFiveText->SetText(FText::FromString(Text));
	}
}

void UVLCCOverlay::SetItemSixText(FString Text)
{
	if(ItemSixText)
	{
		ItemSixText->SetText(FText::FromString(Text));
	}
}
