// Copyright Epic Games, Inc. All Rights Reserved.

#include "MortalCryGameMode.h"
#include "UI/MortalCryHUD.h"
#include "Team/TeamSettings.h"
#include "UObject/ConstructorHelpers.h"

AMortalCryGameMode::AMortalCryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMortalCryHUD::StaticClass();
}

void AMortalCryGameMode::StartPlay()
{
	Super::StartPlay();
	FGenericTeamId::SetAttitudeSolver(&UTeamSettings::GetAttitude);
}
