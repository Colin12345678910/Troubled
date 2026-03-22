// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EActionContext.h"
class UStateMachine;
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

	virtual FString GetName() = 0;
	
	FinState(UStateMachine* stateMachine)
	{
		this->stateMachine = stateMachine;
	};
	virtual ~FinState() { };

	UStateMachine* GetStateMachine() const
	{
		return this->stateMachine;
	};
private:
	UStateMachine* stateMachine;
};

class TraitorState : public FinState
{
public:
	TraitorState(UStateMachine* StateMachine) : FinState(StateMachine) {}

	virtual void Client_OnActionContext(EActionContext ctx) {};
	virtual void Server_OnActionContext(EActionContext ctx) {};
};
