// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCCHUD.h"
#include "GameFramework/PlayerController.h"
#include "VLCCOverlay.h"

void AVLCCHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AVLCCHUD::AddVLCCOverlay()
{
	APlayerController* PlayerController = GetOwningPlayerController();
	if (PlayerController && VLCCOverlayClass)
	{
		VLCCOverlay = CreateWidget<UVLCCOverlay>(PlayerController, VLCCOverlayClass);
		VLCCOverlay->AddToViewport();
	}
}

void AVLCCHUD::DrawHUD()
{
	Super::DrawHUD();
}
