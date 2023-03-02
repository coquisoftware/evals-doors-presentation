// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSObjectiveAccessRequirementComponent.h"
#include "CSJumpObjectiveAccessRequirementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSJumpObjectiveAccessRequirementComponent : public UCSObjectiveAccessRequirementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSJumpObjectiveAccessRequirementComponent();

	virtual bool HasRequirementBeenMet_Implementation() const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Callback invoked when player jumps
	UFUNCTION()
	void OnPlayerJump();

public:

	UPROPERTY(EditAnywhere, Category = Config)
	int NumJumpsNeeded;

protected:
	
	UPROPERTY(BlueprintReadOnly)
	int NumPlayerJumps;

};
