// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCCPlayerController.h"
#include "VLCCHUD.h"
#include "VLCCOverlay.h"
#include "VLCCCharacter.h"

void AVLCCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	VLCCHUD = Cast<AVLCCHUD>(GetHUD());
	VLCCHUD->AddVLCCOverlay();
	AVLCCCharacter* VLCCCharacter = Cast<AVLCCCharacter>(GetCharacter());
	InitItems(VLCCCharacter->GetNumberOfItems());
	SetHUDCollected();
}

void AVLCCPlayerController::SetHUDCollected()
{
	VLCCHUD = VLCCHUD == nullptr ? Cast<AVLCCHUD>(GetHUD()) : VLCCHUD;

	if (VLCCHUD && VLCCHUD->VLCCOverlay)
	{
		int32 NumCollected = 0;
		for (bool Collected : CollectedItems)
		{
			if (Collected) NumCollected++;
		}
		VLCCHUD->VLCCOverlay->SetCollected(NumCollected, CollectedItems.Num());
	}
}

void AVLCCPlayerController::UpdateHUDCollected(int32 Index)
{
	VLCCHUD = VLCCHUD == nullptr ? Cast<AVLCCHUD>(GetHUD()) : VLCCHUD;
	
	CollectedItems[Index] = true;
	if (VLCCHUD && VLCCHUD->VLCCOverlay)
	{
		switch (Index)
		{
			case 0:
				VLCCHUD->VLCCOverlay->SetItemOneText(ItemOneName);
				break;
			case 1:
				VLCCHUD->VLCCOverlay->SetItemTwoText(ItemTwoName);
				break;
			case 2:
				VLCCHUD->VLCCOverlay->SetItemThreeText(ItemThreeName);
				break;
			case 3:
				VLCCHUD->VLCCOverlay->SetItemFourText(ItemFourName);
				break;
			case 4:
				VLCCHUD->VLCCOverlay->SetItemFiveText(ItemFiveName);
				break;
			case 5:
				VLCCHUD->VLCCOverlay->SetItemSixText(ItemSixName);
				break;
		}
	}
	SetHUDCollected();
}
