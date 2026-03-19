#include "TraitorIdleState.h"
#include "StateMachine.h"
#include "TTTCharacter.h"
void TraitorIdleState::OnInitialization()
{
}

void TraitorIdleState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorIdleState::OnEnter"));
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());

	statemachine->SecondaryStart.BindLambda([=]()
	{
		statemachine->TransitionState(statemachine->GetCharacter()->aimState.Get());
	});
}

void TraitorIdleState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorIdleState::OnExit"));
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
	statemachine->SecondaryEnd.Unbind();
}

void TraitorIdleState::Update()
{
}