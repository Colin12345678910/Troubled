#pragma once
#include "CoreMinimal.h"
#include "FinState.h"

class StateMachine
{
public:
	void Update();
	void TransitionState(FinState* state);

private:
	FinState* currentState = nullptr;
};
