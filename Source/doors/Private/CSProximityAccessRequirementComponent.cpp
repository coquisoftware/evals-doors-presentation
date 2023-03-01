// Fill out your copyright notice in the Description page of Project Settings.


#include "CSProximityAccessRequirementComponent.h"

#include "Engine/TriggerVolume.h"


// Sets default values for this component's properties
UCSProximityAccessRequirementComponent::UCSProximityAccessRequirementComponent()
{
	TriggerVolume->OnActorBeginOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorBeginOverlap);
	TriggerVolume->OnActorEndOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorEndOverlap);
}

bool UCSProximityAccessRequirementComponent::RequirementHasBeenMet() const
{
	return Super::RequirementHasBeenMet();
}


// Called when the game starts
void UCSProximityAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCSProximityAccessRequirementComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// @TODO
	for(FName tag : OverlappedActor->Tags)
	{
		if(tag.IsNone())
		{
			break;
		}
	}
	
	for(FName tag : OtherActor->Tags)
	{
		if(tag.IsNone())
		{
			break;
		}
	}
	
}

void UCSProximityAccessRequirementComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// @TODO
	for(FName tag : OverlappedActor->Tags)
	{
		if(tag.IsNone())
		{
			break;
		}
	}
	
	for(FName tag : OtherActor->Tags)
	{
		if(tag.IsNone())
		{
			break;
		}
	}
}


