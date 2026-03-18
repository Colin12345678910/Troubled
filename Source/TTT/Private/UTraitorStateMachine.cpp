#include "UTraitorStateMachine.h"
#include "TTTCharacter.h"
#include "Engine/DamageEvents.h"

void UTraitorStateMachine::FireWeapon_Implementation()
{
	FVector pViewPointLocation;
	FRotator pViewPointRotation;

	auto world = GetWorld();

	if (world)
	{
		this->character->Controller->GetPlayerViewPoint(OUT pViewPointLocation, OUT pViewPointRotation);

		UE_LOG(LogTemp, Log, TEXT("Pew, Pew"));
		FCollisionQueryParams CollisionParams(FName(""), false, this->GetCharacter());
		FVector endPoint = pViewPointLocation + pViewPointRotation.Vector() * 1000.0f;
		FHitResult hit;

		DrawDebugLine(world, pViewPointLocation, endPoint, FColor::Red, true, 30.0f, 0, 4);
		if (world->LineTraceSingleByChannel(OUT hit, pViewPointLocation, endPoint, ECC_Visibility, CollisionParams))
		{
			
			UE_LOG(LogTemp, Log, TEXT("Hit"));
			FDamageEvent damageEvent;
			damageEvent.DamageTypeClass = nullptr;
			if (hit.GetActor() != this->character)
				hit.GetActor()->TakeDamage(50.0f, damageEvent, this->character->Controller, this->GetOwner());
		}
	}
}

UTraitorStateMachine::UTraitorStateMachine()
{
	
}

void UTraitorStateMachine::Initialize(ATTTCharacter* ch)
{
	this->character = ch;
}

UTraitorStateMachine::UTraitorStateMachine(ATTTCharacter* character)
{
	this->Initialize(character);
}