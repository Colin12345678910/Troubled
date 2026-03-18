#pragma once
#include "FinState.h"

class TraitorAimState : public FinState
{
public:
	virtual void OnInitialization() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;


	TraitorAimState(StateMachine* StateMachine) : FinState(StateMachine) {}
};
