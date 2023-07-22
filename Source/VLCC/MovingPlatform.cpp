// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActivePads > 0)
	{
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();
		if (JourneyTravelled > JourneyLength)
		{
			if (bLoop)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}
			else return;
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Speed * Direction * DeltaTime;
		SetActorLocation(Location);
	}
}

void AMovingPlatform::AddActivePad()
{
	ActivePads++;
}

void AMovingPlatform::RemoveActivePad()
{
	if (ActivePads > 0) ActivePads--;
}
