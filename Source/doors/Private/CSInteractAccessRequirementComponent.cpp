// Fill out your copyright notice in the Description page of Project Settings.


#include "CSInteractAccessRequirementComponent.h"
#include "CSCharacterInteractionComponent.h"
#include "CSInteractableInterface.h"
#include "doorsCharacter.h"



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

bool UCSInteractAccessRequirementComponent::HasRequirementBeenMet_Implementation() const
{
	return Super::HasRequirementBeenMet() && bHasBeenInteractedWith;
}

void UCSInteractAccessRequirementComponent::SetInteractStatus(bool bStatus)
{
	bHasBeenInteractedWith = bStatus;
	CheckAndNotifyAccessRequirementStatusChange();
}

void UCSInteractAccessRequirementComponent::ToggleInteractStatus()
{
	bHasBeenInteractedWith = !bHasBeenInteractedWith;
	CheckAndNotifyAccessRequirementStatusChange();
}


void UCSInteractAccessRequirementComponent::OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	bHasBeenInteractedWith = false;
	Super::OnActorBeginOverlap(OverlappedActor, OtherActor);

	if(AdoorsCharacter* DoorsChar = Cast<AdoorsCharacter>(OtherActor))
	{
		if(UCSCharacterInteractionComponent* DoorsCharInteractionComp = DoorsChar->GetInteractionComponent())
		{
			AActor* Door = OverlappedActor->GetAttachParentActor();
			check(Door && Door->Implements<UCSInteractableInterface>())
			DoorsCharInteractionComp->SetInterfacableActor(Door);
		}
	}
}

void UCSInteractAccessRequirementComponent::OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Super::OnActorEndOverlap(OverlappedActor, OtherActor);

	if(AdoorsCharacter* DoorsChar = Cast<AdoorsCharacter>(OtherActor))
	{
		if(UCSCharacterInteractionComponent* DoorsCharInteractionComp = DoorsChar->GetInteractionComponent())
		{
			DoorsCharInteractionComp->SetInterfacableActor(nullptr);
		}
	}
}
