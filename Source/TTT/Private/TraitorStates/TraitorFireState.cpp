#include "TraitorFireState.h"
#include "StateMachine.h"
#include "TTTCharacter.h"
#include "Engine/DamageEvents.h"

void TraitorFireState::OnInitialization()
{
}

void TraitorFireState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorFireState::OnEnter"));
	//I'm not the biggest fan of requiring casting to get the correct Statemachine, it's not that much harder
	// all things considered, but it's an area where issues could arise.
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());

	FVector pViewPointLocation;
	FRotator pViewPointRotation;
	
	auto world = statemachine->GetWorld();
	
	if (world)
	{
		auto character = statemachine->GetCharacter();
		character->Controller->GetPlayerViewPoint(OUT pViewPointLocation, OUT pViewPointRotation);
	
		UE_LOG(LogTemp, Log, TEXT("Pew, Pew"));
		FCollisionQueryParams CollisionParams(FName(""), false, character);
		FVector endPoint = pViewPointLocation + pViewPointRotation.Vector() * 1000.0f;
		FHitResult hit;
	
		DrawDebugLine(world, pViewPointLocation, endPoint, FColor::Red, true, 30.0f, 0, 4);
		if (world->LineTraceSingleByChannel(OUT hit, pViewPointLocation, endPoint, ECC_Visibility, CollisionParams))
		{
			
			UE_LOG(LogTemp, Log, TEXT("Hit"));
			FDamageEvent damageEvent;
			damageEvent.DamageTypeClass = nullptr;
			if (hit.GetActor() != character)
				hit.GetActor()->TakeDamage(50.0f, damageEvent, character->Controller, character->GetOwner());
		}
	}

	FTimerDelegate timerDelegate;
	timerDelegate.BindLambda([statemachine]()
	{
		if (statemachine)
		{
			statemachine->TransitionState(ETraitorState::IDLE_STATE);
		}
	});
	
	statemachine->GetWorld()->GetTimerManager().SetTimer(fireGunTimer, timerDelegate, 1.0f, false);
}

void TraitorFireState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TraitorFireState::OnExit"));
	
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
}

void TraitorFireState::Update()
{
}