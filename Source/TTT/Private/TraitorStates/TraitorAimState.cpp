#include "TraitorAimState.h"

#include "StateMachine.h"
#include "TTTCharacter.h"

void TraitorAimState::OnInitialization()
{
}

void TraitorAimState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorAimState::OnEnter"));

	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());

	statemachine->FireWeapon();
}

void TraitorAimState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TraitorAimState::OnExit"));
}

void TraitorAimState::Update()
{
}