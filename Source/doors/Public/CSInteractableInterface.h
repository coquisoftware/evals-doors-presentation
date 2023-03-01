﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CSInteractableInterface.generated.h"

class APawn;
// This class does not need to be modified.
UINTERFACE()
class UCSInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DOORS_API ICSInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION()
	virtual void Interact(APawn* InstigatorPawn);
};
