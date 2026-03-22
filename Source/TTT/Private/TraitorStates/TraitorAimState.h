#pragma once
#include "FinState.h"

class TraitorAimState : public TraitorState
{
public:
	virtual void OnInitialization() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;
	virtual FString GetName() override { return TEXT("TraitorAimState"); }

	virtual void Server_OnActionContext(EActionContext ctx) override;
	
	TraitorAimState(UStateMachine* StateMachine) : TraitorState(StateMachine) {}
};
