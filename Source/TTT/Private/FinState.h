// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
class StateMachine;
/** A Basic Implementation of a StateMachine.
 * 
 */
class FinState
{
public:
	virtual void OnInitialization() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void Update() = 0;
	
	FinState(StateMachine* stateMachine)
	{
		this->stateMachine = stateMachine;
	};
	virtual ~FinState() { };

	StateMachine* GetStateMachine() const
	{
		return this->stateMachine;
	};
private:
	StateMachine* stateMachine;
};

class UTraitorStateMachine;
class TraitorState : public FinState
{
public:
	TraitorState(StateMachine* StateMachine) : FinState(StateMachine) {}
};
