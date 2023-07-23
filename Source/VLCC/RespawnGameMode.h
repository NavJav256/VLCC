// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RespawnGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDiedSignature, ACharacter*, Character);

/**
 * 
 */
UCLASS()
class VLCC_API ARespawnGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

    const FOnPlayerDiedSignature& GetOnPlayerDied() const { return OnPlayerDied; }

    virtual void RestartPlayer(AController* NewPlayer) override;

protected:

    virtual void BeginPlay() override;

    UFUNCTION()
    virtual void PlayerDied(ACharacter* Character);

    UPROPERTY()
    FOnPlayerDiedSignature OnPlayerDied;
};
