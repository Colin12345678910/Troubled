// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "TTTCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "TTTGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS(abstract)
class ATTTGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATTTGameMode();
	void PostLogin(APlayerController* NewPlayer) override;
	void PlayerDied(APlayerController* player);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<class ATTTCharacter> InnocentCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<class ATTTCharacter> TraitorCharacter;
private:
	std::vector<APlayerController*> players;
	void InitializeGame();
};



