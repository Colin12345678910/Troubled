class ATTTCharacter;
#pragma once
#include "CoreMinimal.h"
#include "StateMachine.h"
#include "UTraitorStateEnum.h"
#include "UTraitorStateMachine.generated.h"

/*
	A Basic implementation of a client-sided state machine, transitions are entirely up to the client, so this is best used
	for effects that either prove no real benefit to the end user (Taunts, Aiming, Weapon swapping.) and if an event could be cheated
	like firing a weapon, the state should call an implemented function on this statemachine, where the server will then do verification.
 */
UCLASS(ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent))
class UTraitorStateMachine : public UStateMachine
{
	GENERATED_BODY()
public:
	virtual std::unordered_map<int, TSharedPtr<FinState>>& GetTransitionStates() override
	{
		return transitionStates;
	}
	
	void Initialize(ATTTCharacter* ch);
	UTraitorStateMachine(ATTTCharacter* character);

	ATTTCharacter* GetCharacter()
	{
		return character;
	}
	
	UFUNCTION(BlueprintCallable, Category="CInput")
	void DoPrimaryStart()
	{
		Client_ActionContext(EActionContext::PrimaryBegin);
		Server_ActionContext(EActionContext::PrimaryBegin);
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	void DoPrimaryEnd()
	{
		Client_ActionContext(EActionContext::PrimaryEnd);
		Server_ActionContext(EActionContext::PrimaryEnd);
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	void DoSecondaryStart()
	{
		Client_ActionContext(EActionContext::SecondaryBegin);
		Server_ActionContext(EActionContext::SecondaryBegin);
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	void DoSecondaryEnd()
	{
		Client_ActionContext(EActionContext::SecondaryEnd);
		Server_ActionContext(EActionContext::SecondaryEnd);
	};

	DECLARE_DELEGATE(FInputDelegate);

	FInputDelegate PrimaryStart;
	FInputDelegate PrimaryEnd;
	FInputDelegate SecondaryStart;
	FInputDelegate SecondaryEnd;

	UFUNCTION(Server, Reliable)
	void Server_ActionContext(EActionContext ctx);
	void Client_ActionContext(EActionContext ctx);
	
	UFUNCTION(Server, Reliable)
	void FireWeapon();
	
	UTraitorStateMachine();
private:
	ATTTCharacter* character = nullptr;
	
	std::unordered_map<int, TSharedPtr<FinState>> transitionStates{};
};