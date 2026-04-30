// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Delegates/DelegateCombinations.h"
#include "TTTGameState.generated.h"

// A multicast delegate that passes one float parameter
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

/**
 * 
 */
UCLASS()
class TTT_API ATTTGameState : public AGameState
{
	GENERATED_BODY()
public:

	
};
