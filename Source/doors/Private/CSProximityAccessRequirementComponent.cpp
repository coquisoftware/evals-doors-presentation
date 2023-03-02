// Fill out your copyright notice in the Description page of Project Settings.


#include "CSProximityAccessRequirementComponent.h"

#include "CSDoor.h"
#include "CSTriggerBox.h"


// Sets default values for this component's properties
UCSProximityAccessRequirementComponent::UCSProximityAccessRequirementComponent()
{
	bIsCharacterInTriggerVolume = false;
	TriggerVolume = nullptr;
}

bool UCSProximityAccessRequirementComponent::HasRequirementBeenMet() const
{
	return bIsCharacterInTriggerVolume;
}


// Called when the game starts
void UCSProximityAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ChildActors;
	if(ACSDoor* DoorOwner = Cast<ACSDoor>(GetOwner()))
	{
		TriggerVolume = DoorOwner->GetTriggerBoxVolume();
		
		if(TriggerVolume != nullptr)
		{
			TriggerVolume->OnActorBeginOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorBeginOverlap);
			TriggerVolume->OnActorEndOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorEndOverlap);
		}
	}
	
}

void UCSProximityAccessRequirementComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// @TODO Check if OtherActor is PlayerCharacter
	bIsCharacterInTriggerVolume = true;
	CheckAndNotifyAccessRequirementStatusChange();
}

void UCSProximityAccessRequirementComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// @TODO Check if OtherActor is PlayerCharacter
	bIsCharacterInTriggerVolume = false;
	CheckAndNotifyAccessRequirementStatusChange();
}


