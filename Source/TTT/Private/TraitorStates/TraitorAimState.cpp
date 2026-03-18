#include "TraitorAimState.h"

#include "StateMachine.h"
#include "TTTCharacter.h"

void TraitorAimState::OnInitialization()
{
}

void TraitorAimState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorAimState::OnEnter"));

	auto character = static_cast<TraitorStateMachine*>(GetStateMachine())->GetCharacter();

	character->DoShoot();
}

void TraitorAimState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TraitorAimState::OnExit"));
}

void TraitorAimState::Update()
{
}