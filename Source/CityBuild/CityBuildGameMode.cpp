// Copyright Epic Games, Inc. All Rights Reserved.

#include "CityBuildGameMode.h"
#include "CityBuildPlayerController.h"
#include "CityBuildCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACityBuildGameMode::ACityBuildGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACityBuildPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}