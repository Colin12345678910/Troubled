#pragma once
#include "FinState.h"

class TraitorAimState : public TraitorState
{
public:
	virtual void OnInitialization() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;
	
	TraitorAimState(StateMachine* StateMachine) : TraitorState(StateMachine) {}
};
