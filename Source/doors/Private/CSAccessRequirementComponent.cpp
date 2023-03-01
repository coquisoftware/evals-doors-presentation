// Fill out your copyright notice in the Description page of Project Settings.


#include "CSAccessRequirementComponent.h"


// Sets default values for this component's properties
UCSAccessRequirementComponent::UCSAccessRequirementComponent()
{
	

	// ...
}


void UCSAccessRequirementComponent::CheckAndNotifyAccessRequirementStatusChange(bool bNewStatus)
{
	if(bNewStatus != HasRequirementBeenMet())
	{
		OnAccessRequirementStatusChange.Broadcast(bNewStatus);
	}
}

// Called when the game starts
void UCSAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



