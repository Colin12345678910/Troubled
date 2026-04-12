// Copyright Epic Games, Inc. All Rights Reserved.

#include "TTTGameMode.h"

#include "TTTPlayerState.h"
#include "Algo/RandomShuffle.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"

ATTTGameMode::ATTTGameMode()
{
}

void ATTTGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	auto World = GetWorld();
	int p = World->GetGameState()->PlayerArray.Num();
	UE_LOG(LogTemp, Warning, TEXT("Players: %d"), p);

	players.push_back(NewPlayer);
}

void ATTTGameMode::PlayerDied(APlayerController* player)
{
	auto World = GetWorld();
	if (World && HasAuthority())
	{
		player->GetPawn()->Destroy(); //Kill the pawn...
		GEngine->AddOnScreenDebugMessage(0, 10.f, FColor::Red, TEXT("Restarting server with authority"));
		
		//Todo: Replace with a next map selector.
		GetWorld()->ServerTravel("Lvl_FirstPerson?listen", true);
	}
}

void ATTTGameMode::InitializeGame()
{
	auto World = GetWorld();
	auto arr = World->GetGameState()->PlayerArray;
		Algo::RandomShuffle(arr);
		
	auto playerState = static_cast<ATTTPlayerState*>(arr[0]);
	
	playerState->OnJoinMatch("You are the traitor");
	playerState->OurRole = CharacterRole::TRAITOR;

	for (auto player : players)
	{
		playerState = static_cast<ATTTPlayerState*>(player->PlayerState);
		
		auto spawnPoint = FindPlayerStart(player);
		auto spawnTransform = spawnPoint->GetTransform();
	
		APawn* newPawn = nullptr;
		
		switch (playerState->OurRole)
		{
			case CharacterRole::TRAITOR:
				newPawn = GetWorld()->SpawnActor<ATTTCharacter>(TraitorCharacter, spawnTransform);
				UE_LOG(LogTemp, Warning, TEXT("TraitorSpawn"));
				break;
			case CharacterRole::SHERIFF:
				break;
			case CharacterRole::INNOCENT:
				newPawn = GetWorld()->SpawnActor<ATTTCharacter>(InnocentCharacter, spawnTransform);
			UE_LOG(LogTemp, Warning, TEXT("InnocentSpawn"));
				break;
		}
		
		if (newPawn != nullptr)
		{
			auto oldPawn = player->GetPawn();
			if (oldPawn != nullptr)
			{
				oldPawn->Destroy();
			}
			player->Possess(newPawn);	
		}
	}
}

