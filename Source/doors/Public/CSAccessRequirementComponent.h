﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSAccessRequirementComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAccessRequirementStatusChange, bool, bIsRequirementMet)

UCLASS(Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSAccessRequirementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSAccessRequirementComponent();

	virtual bool HasRequirementBeenMet() const PURE_VIRTUAL(, return false;);

	void CheckAndNotifyAccessRequirementStatusChange(bool bNewStatus);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	FOnAccessRequirementStatusChange OnAccessRequirementStatusChange;
	
};
