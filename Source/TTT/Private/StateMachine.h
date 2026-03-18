#pragma once
#include "CoreMinimal.h"
#include "FinState.h"

class ATTTCharacter;

class StateMachine
{
public:
	void Update();
	void TransitionState(FinState* state);

private:
	FinState* currentState = nullptr;
};

class TraitorStateMachine : public StateMachine
{
public:
	void Initialize(ATTTCharacter* ch);
	TraitorStateMachine(ATTTCharacter* character);

	ATTTCharacter* GetCharacter() { return character; }
private:
	ATTTCharacter* character = nullptr;
};
