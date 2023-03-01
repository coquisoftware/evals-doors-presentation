// Fill out your copyright notice in the Description page of Project Settings.


#include "CSInteractAccessRequirementComponent.h"


// Sets default values for this component's properties
UCSInteractAccessRequirementComponent::UCSInteractAccessRequirementComponent()
{
	bHasBeenInteractedWith = false;
}

// Called when the game starts
void UCSInteractAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

}

bool UCSInteractAccessRequirementComponent::HasRequirementBeenMet() const
{
	return Super::HasRequirementBeenMet() && bHasBeenInteractedWith;
}

void UCSInteractAccessRequirementComponent::SetInteractStatus(bool bStatus)
{
	CheckAndNotifyAccessRequirementStatusChange(bStatus);
	bHasBeenInteractedWith = bStatus;
}
