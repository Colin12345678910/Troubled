#include "StateMachine.h"

#include "Net/UnrealNetwork.h"

void UStateMachine::Update()
{
	if (GetOwner()->HasAuthority())
	{
		GetState()->Update();
	}
	else
	{
		
	}
}

void UStateMachine::TransitionState(int stateEnum)
{
	if (GetOwner()->HasAuthority())
	{
		if (ECurrentState == stateEnum)
		{
			return;
		}
		if (ECurrentState)
		{
			GetState()->OnExit();
		}
		ECurrentState = stateEnum;
		GetState()->OnEnter();
	}
}

void UStateMachine::Transition_Replication(int stateEnum)
{
	ECurrentState = stateEnum;
}

void UStateMachine::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UStateMachine, ECurrentState);
}