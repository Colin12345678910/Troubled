class ATTTCharacter;
#pragma once
#include "CoreMinimal.h"
#include "StateMachine.h"
#include "UTraitorStateMachine.generated.h"

UCLASS(ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent))
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
	
	UFUNCTION(BlueprintCallable, Category="CInput")
	virtual void DoPrimaryStart()
	{
		PrimaryStart.ExecuteIfBound();
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	virtual void DoPrimaryEnd()
	{
		PrimaryEnd.ExecuteIfBound();
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	virtual void DoSecondaryStart()
	{
		SecondaryStart.ExecuteIfBound();
	};

	UFUNCTION(BlueprintCallable, Category="CInput")
	virtual void DoSecondaryEnd()
	{
		SecondaryEnd.ExecuteIfBound();
	};

	DECLARE_DELEGATE(FInputDelegate);

	FInputDelegate PrimaryStart;
	FInputDelegate PrimaryEnd;
	FInputDelegate SecondaryStart;
	FInputDelegate SecondaryEnd;
	
	UFUNCTION(Server, Reliable)
	void FireWeapon();
	
	UTraitorStateMachine();
private:
	ATTTCharacter* character = nullptr;
};