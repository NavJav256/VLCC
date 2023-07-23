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
	CollectedItems[Index] = true;
	SetHUDCollected();
}
