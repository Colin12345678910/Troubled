#include "TraitorAimState.h"
#include "StateMachine.h"
#include "TTTCharacter.h"
void TraitorAimState::OnInitialization()
{
}

void TraitorAimState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorAimState::OnEnter"));
	//I'm not the biggest fan of requiring casting to get the correct Statemachine, it's not that much harder
	// all things considered, but it's an area where issues could arise.
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());

	statemachine->SecondaryEnd.BindLambda([=]()
	{
		statemachine->TransitionState(statemachine->GetCharacter()->idleState.Get());
	});

	statemachine->PrimaryStart.BindLambda([=]()
	{
		statemachine->FireWeapon();
		statemachine->TransitionState(statemachine->GetCharacter()->idleState.Get());
	});
}

void TraitorAimState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TraitorAimState::OnExit"));
	
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
	statemachine->PrimaryStart.Unbind();
	statemachine->PrimaryStart.Unbind();
}

void TraitorAimState::Update()
{
}