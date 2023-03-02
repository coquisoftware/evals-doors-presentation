// Fill out your copyright notice in the Description page of Project Settings.


#include "CSProximityAccessRequirementComponent.h"


#include "CSInteractableInterface.h"
#include "CSTriggerBox.h"


// Sets default values for this component's properties
UCSProximityAccessRequirementComponent::UCSProximityAccessRequirementComponent()
{
	bIsCharacterInTriggerVolume = false;
	TriggerVolume = nullptr;
}

bool UCSProximityAccessRequirementComponent::HasRequirementBeenMet_Implementation() const
{
	return bIsCharacterInTriggerVolume;
}


// Called when the game starts
void UCSProximityAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ChildActors;
	check(GetOwner()->Implements<UCSInteractableInterface>())
	if(ICSInteractableInterface* InteractableOwner = Cast<ICSInteractableInterface>(GetOwner()))
	{
		TriggerVolume = InteractableOwner->GetTriggerBoxVolume();
		
		if(TriggerVolume != nullptr)
		{
			TriggerVolume->OnActorBeginOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorBeginOverlap);
			TriggerVolume->OnActorEndOverlap.AddDynamic(this, &UCSProximityAccessRequirementComponent::OnActorEndOverlap);
		}
	}
	
}

void UCSProximityAccessRequirementComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	bIsCharacterInTriggerVolume = true;
	CheckAndNotifyAccessRequirementStatusChange();
}

void UCSProximityAccessRequirementComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	bIsCharacterInTriggerVolume = false;
	CheckAndNotifyAccessRequirementStatusChange();
}


