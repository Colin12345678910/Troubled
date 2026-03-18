// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TTTGameState.generated.h"

/**
 * 
 */
UCLASS()
class TTT_API ATTTGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(Server, Reliable)
	void JoinMatch(ATTTCharacter* Character);
};
