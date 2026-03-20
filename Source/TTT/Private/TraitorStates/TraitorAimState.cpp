#include "TraitorAimState.h"
#include "StateMachine.h"
#include "TTTCharacter.h"
#include "Engine/DamageEvents.h"

void TraitorAimState::OnInitialization()
{
}

void TraitorAimState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorAimState::OnEnter"));
	//I'm not the biggest fan of requiring casting to get the correct Statemachine, it's not that much harder
	// all things considered, but it's an area where issues could arise.
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
}

void TraitorAimState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TraitorAimState::OnExit"));
	
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
}

void TraitorAimState::Update()
{
}

void TraitorAimState::Server_OnActionContext(EActionContext ctx)
{
	TraitorState::Server_OnActionContext(ctx);
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());

	if (ctx == EActionContext::SecondaryEnd)
	{
		statemachine->TransitionState(ETraitorState::IDLE_STATE);
	}
	if (ctx == EActionContext::PrimaryBegin)
	{
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
	}
}
