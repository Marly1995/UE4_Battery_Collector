// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "Blueprint/UserWidget.h"
#include "BatteryCollectorGameMode.generated.h"


// enum to store current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	// returns power need to win for hud
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin();

	virtual void BeginPlay() override;

	// returns the current playing state
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	// sets a new playing state
	void SetCurrentState(EBatteryPlayState NewState);

protected:
	// rate at which character loses power
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float DecayRate;

	// power needed to win game
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float PowerToWin;

	// widget class to use for our hud screen
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	// one instance of hud
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	// keeps track of current play state
	EBatteryPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;

	// hadle any functio calls that rely upon game state changes
	void HandleNewState(EBatteryPlayState NewState);
};



