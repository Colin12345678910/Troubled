// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTPlayerState.h"

void ATTTPlayerState::OnJoinMatch_Implementation(const FString& data)
{
	GEngine->AddOnScreenDebugMessage(
		0,
		5.0f,
		FColor::Red,
		data
		);

	
}