// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKeyItemAccessRequirementComponent.h"

#include "CSInventoryComponent.h"
#include "doorsCharacter.h"


// Sets default values for this component's properties
UCSKeyItemAccessRequirementComponent::UCSKeyItemAccessRequirementComponent()
{
}

bool UCSKeyItemAccessRequirementComponent::HasRequirementBeenMet_Implementation() const
{
	return bPlayerHasKeyItem;
}


// Called when the game starts
void UCSKeyItemAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	bPlayerHasKeyItem = false;

	if(AdoorsCharacter* DoorsCharacter = Cast<AdoorsCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter()))
	{
		if(UCSInventoryComponent* DoorsCharacterInventory = DoorsCharacter->GetInventory())
		{
			DoorsCharacterInventory->OnInventoryItemAdded.AddDynamic(this, &UCSKeyItemAccessRequirementComponent::OnInventoryItemAdd);
		}
		
	}
	
}

void UCSKeyItemAccessRequirementComponent::OnInventoryItemAdd(ACSKeyInventoryItem* Item)
{
	// Ideally we'd verify that the item retrieved is the one that's required to access this door
	// but for this demo there's only one item available so it's certainly going to be the key
	
	bPlayerHasKeyItem = true;
	CheckAndNotifyAccessRequirementStatusChange();
}


