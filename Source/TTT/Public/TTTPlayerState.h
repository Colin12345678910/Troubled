// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TTTPlayerState.generated.h"

/**
 * 
 */
enum CharacterRole
{
	TRAITOR,
	INNOCENT,
	SHERIFF
};

UCLASS()
class TTT_API ATTTPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UFUNCTION(Client, Reliable)
	void OnJoinMatch(const FString& data);

	CharacterRole OurRole = INNOCENT;
};

