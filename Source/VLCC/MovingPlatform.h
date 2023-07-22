// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class VLCC_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();

	void AddActivePad();

	void RemoveActivePad();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	FVector GlobalStartLocation;
	
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
	FVector TargetLocation;

	UPROPERTY(EditAnywhere)
	float Speed = 200;

	UPROPERTY(EditAnywhere)
	bool bLoop = true;

	UPROPERTY(EditAnywhere)
	int ActivePads = 1;
	
};
