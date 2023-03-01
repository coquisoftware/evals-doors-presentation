// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSDoor.generated.h"

UCLASS()
class DOORS_API ACSDoor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditInstanceOnly)
	FText DoorLabel;
	
public:
	// Sets default values for this actor's properties
	ACSDoor();

	
	bool AreAllAreAccessRequirementsMet() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
