class ATTTCharacter;
#pragma once
#include "CoreMinimal.h"
#include "StateMachine.h"
#include "UTraitorStateMachine.generated.h"

UCLASS(ClassGroup=(Custom))
class UTraitorStateMachine : public UActorComponent, public StateMachine
{
	GENERATED_BODY()
	
public:
	void Initialize(ATTTCharacter* ch);
	UTraitorStateMachine(ATTTCharacter* character);

	ATTTCharacter* GetCharacter()
	{
		return character;
	}
	
	UFUNCTION(Server, Reliable)
	void FireWeapon();
	
	UTraitorStateMachine();
private:
	ATTTCharacter* character = nullptr;
};