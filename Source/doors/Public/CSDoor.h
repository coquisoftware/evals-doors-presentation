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

	UPROPERTY(EditAnywhere)
	FText DoorLabel;
	
public:
	// Sets default values for this actor's properties
	ACSDoor();

	UFUNCTION(BlueprintPure)
	bool AreAllAreAccessRequirementsMet() const;

	UFUNCTION(BlueprintPure)
	FText GetDoorLabel() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
