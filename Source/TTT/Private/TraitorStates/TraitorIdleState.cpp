#include "TraitorIdleState.h"

void TraitorIdleState::OnInitialization()
{
}

void TraitorIdleState::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorIdleState::OnEnter"));
}

void TraitorIdleState::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),  TEXT("TraitorIdleState::OnExit"));
}

void TraitorIdleState::Update()
{
}