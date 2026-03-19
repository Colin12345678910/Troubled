#pragma once
#include "FinState.h"

class TraitorIdleState : public TraitorState
{
public:
	virtual void OnInitialization() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;

	TraitorIdleState(StateMachine* sm) : TraitorState(sm) {}
};
