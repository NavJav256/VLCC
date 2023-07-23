// Fill out your copyright notice in the Description page of Project Settings.


#include "RespawnGameMode.h"
#include "VLCCCharacter.h"

void ARespawnGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (!OnPlayerDied.IsBound())
    {
        OnPlayerDied.AddDynamic(this, &ARespawnGameMode::PlayerDied);
    }
}

void ARespawnGameMode::RestartPlayer(AController* NewPlayer)
{
    Super::RestartPlayer(NewPlayer);
}

void ARespawnGameMode::PlayerDied(ACharacter* Character)
{
    AController* CharacterController = Character->GetController();
    RestartPlayer(CharacterController);
}
