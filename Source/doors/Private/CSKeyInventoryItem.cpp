// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKeyInventoryItem.h"

#include "CSTriggerBox.h"
#include "CSAccessRequirementComponent.h"
#include "CSInteractAccessRequirementComponent.h"


// Sets default values
ACSKeyInventoryItem::ACSKeyInventoryItem()
{
	
}

// Called when the game starts or when spawned
void ACSKeyInventoryItem::BeginPlay()
{
	Super::BeginPlay();

	GetComponents(CachedAccessRequirementComponentsList);
	
}

void ACSKeyInventoryItem::Interact(AdoorsCharacter* InstigatorPawn)
{
	ICSInteractableInterface::Interact(InstigatorPawn);
}

ACSTriggerBox* ACSKeyInventoryItem::GetTriggerBoxVolume()
{
	if(TriggerBoxVolume == nullptr)
	{
		TArray<AActor*> ChildActors;
		GetAttachedActors(ChildActors);

		if(!ChildActors.IsEmpty())
		{
			for(AActor* Child : ChildActors)
			{
				TriggerBoxVolume = Cast<ACSTriggerBox>(Child);
				if(TriggerBoxVolume != nullptr)
				{
					break;
				}
				
			}
			
		}
	}

	return TriggerBoxVolume;
}



