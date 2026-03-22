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
		statemachine->TransitionState(ETraitorState::FIRE_STATE);
	}
}
