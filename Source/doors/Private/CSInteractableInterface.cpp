// Fill out your copyright notice in the Description page of Project Settings.


#include "CSInteractableInterface.h"

#include "CSAccessRequirementComponent.h"
#include "CSInteractAccessRequirementComponent.h"


void ICSInteractableInterface::Interact(AdoorsCharacter* InstigatorPawn)
{
	for(UCSAccessRequirementComponent* ARComponent : CachedAccessRequirementComponentsList)
	{
		if(UCSInteractAccessRequirementComponent* ARInteractComponent = Cast<UCSInteractAccessRequirementComponent>(ARComponent))
		{
			ARInteractComponent->ToggleInteractStatus();
		}
	}
}

ACSTriggerBox* ICSInteractableInterface::GetTriggerBoxVolume()
{
	return TriggerBoxVolume;
}
