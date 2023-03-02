// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSAccessRequirementComponent.h"
#include "CSKeyItemAccessRequirementComponent.generated.h"

class ACSKeyInventoryItem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSKeyItemAccessRequirementComponent : public UCSAccessRequirementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSKeyItemAccessRequirementComponent();

	virtual bool HasRequirementBeenMet_Implementation() const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnInventoryItemAdd(ACSKeyInventoryItem* Item);

private:

	bool bPlayerHasKeyItem;

};
