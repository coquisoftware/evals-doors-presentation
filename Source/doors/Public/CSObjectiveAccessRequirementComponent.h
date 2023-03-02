// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSAccessRequirementComponent.h"
#include "CSObjectiveAccessRequirementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSObjectiveAccessRequirementComponent : public UCSAccessRequirementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSObjectiveAccessRequirementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
};
