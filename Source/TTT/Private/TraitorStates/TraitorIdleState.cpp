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
}

void TraitorIdleState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorIdleState::OnExit"));
	auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
}

void TraitorIdleState::Update()
{
}

void TraitorIdleState::Server_OnActionContext(EActionContext ctx)
{
	TraitorState::Server_OnActionContext(ctx);

	if (ctx == EActionContext::SecondaryBegin)
	{
		auto statemachine = static_cast<UTraitorStateMachine*>(GetStateMachine());
		statemachine->TransitionState(ETraitorState::AIM_STATE);
	}
}
