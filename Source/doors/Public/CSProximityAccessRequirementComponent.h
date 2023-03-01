﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSAccessRequirementComponent.h"
#include "Components/ActorComponent.h"
#include "CSProximityAccessRequirementComponent.generated.h"

class ATriggerBox;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSProximityAccessRequirementComponent : public UCSAccessRequirementComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(Transient, EditInstanceOnly)
	ATriggerBox* TriggerVolume;
	
public:
	// Sets default values for this component's properties
	UCSProximityAccessRequirementComponent();

	UFUNCTION(BlueprintPure)
	virtual bool RequirementHasBeenMet() const;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
