// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKeyInventoryItem.h"

#include "CSTriggerBox.h"


// Sets default values
ACSKeyInventoryItem::ACSKeyInventoryItem()
{
	
}

void ACSKeyInventoryItem::Interact(AdoorsCharacter* InstigatorPawn)
{
	
	
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
				if(TriggerBoxVolume = Cast<ACSTriggerBox>(Child))
				{
					break;
				}
				
			}
			
		}
	}

	return TriggerBoxVolume;
}

// Called when the game starts or when spawned
void ACSKeyInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

