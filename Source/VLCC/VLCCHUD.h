// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VLCCHUD.generated.h"

/**
 * 
 */
UCLASS()
class VLCC_API AVLCCHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	virtual void DrawHUD() override;

	UPROPERTY()
	class UVLCCOverlay* VLCCOverlay;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<class UUserWidget> VLCCOverlayClass;

	void AddVLCCOverlay();

protected:

	virtual void BeginPlay() override;
};
