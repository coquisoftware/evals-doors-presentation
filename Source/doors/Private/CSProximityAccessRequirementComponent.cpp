// Fill out your copyright notice in the Description page of Project Settings.


#include "CSProximityAccessRequirementComponent.h"

#include "CSTriggerBox.h"


// Sets default values for this component's properties
UCSProximityAccessRequirementComponent::UCSProximityAccessRequirementComponent()
{
	
}

bool UCSProximityAccessRequirementComponent::RequirementHasBeenMet() const
{
	return Super::RequirementHasBeenMet();
}


// Called when the game starts
void UCSProximityAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ChildActors;
	if(AActor* DoorOwner = GetOwner())
	{
		DoorOwner->GetAttachedActors(ChildActors);
	}

	TriggerVolume = Cast<ACSTriggerBox>(ChildActors[0]);
	
	if(TriggerVolume != nullptr)
	{
		TriggerVolume->OnActorBeginOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorBeginOverlap);
		TriggerVolume->OnActorEndOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorEndOverlap);
	}
	
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


