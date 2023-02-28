// Copyright Epic Games, Inc. All Rights Reserved.

#include "doorsGameMode.h"
#include "doorsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AdoorsGameMode::AdoorsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
