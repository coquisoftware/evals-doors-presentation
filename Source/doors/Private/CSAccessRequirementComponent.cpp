// Fill out your copyright notice in the Description page of Project Settings.


#include "CSAccessRequirementComponent.h"


// Sets default values for this component's properties
UCSAccessRequirementComponent::UCSAccessRequirementComponent()
{
	

	// ...
}


void UCSAccessRequirementComponent::CheckAndNotifyAccessRequirementStatusChange()
{
	const bool bHasRequirementNowBeenMet = HasRequirementBeenMet();
	if(bHasRequirementNowBeenMet != bCachedRequirementMet)
	{
		OnAccessRequirementStatusChange.Broadcast(bHasRequirementNowBeenMet);
		bCachedRequirementMet = bHasRequirementNowBeenMet;
	}
}

// Called when the game starts
void UCSAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



