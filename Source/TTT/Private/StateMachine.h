#pragma once
#include "CoreMinimal.h"
#include <string>

#include "FinState.h"
#include "unordered_map"
#include "StateMachine.generated.h"

UCLASS(Abstract, ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent))
class UStateMachine : public UActorComponent
{
	GENERATED_BODY()
public:
	void Update();
	void TransitionState(int stateEnum);
	UFUNCTION()
	void Transition_Replication(int stateEnum);

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UStateMachine* GetBaseMachine() { return this; }
	virtual const std::unordered_map<int, TSharedPtr<FinState>>& GetTransitionStates()
	{
		static std::unordered_map<int, TSharedPtr<FinState>> Empty;
		return Empty;
	};
	FinState* GetState()
	{
		auto map = this->GetTransitionStates();
		return map.contains(ECurrentState) ? map[ECurrentState].Get() : map.begin()->second.Get();
	};
protected:
	//Note, this is a raw Int, raw ints should never be passed, but templates don't work under unreal UProperties/Classes so to maintain flexibility it must remain an int.
	UPROPERTY(meta = (AllowPrivateAccess = "true"), Replicated, BlueprintReadOnly, Category="-State")
	int ECurrentState = 0;
};
