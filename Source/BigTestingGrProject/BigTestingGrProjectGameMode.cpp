// Copyright Epic Games, Inc. All Rights Reserved.

#include "BigTestingGrProjectGameMode.h"
#include "BigTestingGrProjectHUD.h"
#include "BigTestingGrProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABigTestingGrProjectGameMode::ABigTestingGrProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABigTestingGrProjectHUD::StaticClass();
}
