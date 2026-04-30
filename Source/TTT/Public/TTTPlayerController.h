// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TTTPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;

/**
 *  Simple first person Player Controller
 *  Manages the input mapping context.
 *  Overrides the Player Camera Manager class.
 */
UCLASS(abstract, config="Game")
class TTT_API ATTTPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	ATTTPlayerController();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameHUD")
	TSubclassOf<UUserWidget> mainHUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameHUD")
	TSubclassOf<UUserWidget> pregameHUD;

	// Not very clean, but functional for only 2 different huds
	void ChangeToMainHUD() { ChangeHUD(mainHUD); }
	void ChangeToPregameHUD() { ChangeHUD(pregameHUD); }
protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** If true, the player will use UMG touch controls even if not playing on mobile platforms */
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
	void RequestMatchStart();
	UFUNCTION(Server, Reliable)
	void MatchStart();
	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;

	void ChangeHUD(TSubclassOf<UUserWidget> widget);

private:
	UUserWidget* HUDWidget;
};
