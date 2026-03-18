#include "StateMachine.h"

void StateMachine::Update()
{
	currentState->Update();
}

void StateMachine::TransitionState(FinState* state)
{
	if (currentState == state)
	{
		return;
	}
	if (currentState)
	{
		currentState->OnExit();
	}
	currentState = state;
	currentState->OnEnter();
}