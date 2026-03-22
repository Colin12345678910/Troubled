#pragma once
#include "FinState.h"

class TraitorFireState : public TraitorState
{
public:
	virtual void OnInitialization() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void Update() override;
	virtual FString GetName() override { return TEXT("TraitorFireState"); }
	TraitorFireState(UStateMachine* StateMachine) : TraitorState(StateMachine) {}

protected:
	FTimerHandle fireGunTimer;
};
