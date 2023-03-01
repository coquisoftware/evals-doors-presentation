// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "CSTriggerBox.generated.h"

UCLASS()
class DOORS_API ACSTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACSTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
