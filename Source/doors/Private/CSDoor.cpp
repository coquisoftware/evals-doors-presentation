// Fill out your copyright notice in the Description page of Project Settings.


#include "doors/Public/CSDoor.h"

#include "CSAccessRequirementComponent.h"
#include "CSInteractAccessRequirementComponent.h"
#include "CSTriggerBox.h"


// Sets default values
ACSDoor::ACSDoor()
{
	bIsDoorOpen = false;
}

bool ACSDoor::AreAllAreAccessRequirementsMet() const
{
	bool bResult = true;

	for(const UCSAccessRequirementComponent* AccessRequirementComponent : CachedAccessRequirementComponentsList)
	{
		if(!AccessRequirementComponent->HasRequirementBeenMet())
		{
			bResult = false;
			break;
		}
	}

	return bResult;
	
}

FText ACSDoor::GetDoorLabel() const
{
	return DoorLabel;
}

ACSTriggerBox* ACSDoor::GetTriggerBoxVolume()
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

void ACSDoor::Interact(AdoorsCharacter* InstigatorPawn)
{
	ICSInteractableInterface::Interact(InstigatorPawn);
}

// Called when the game starts or when spawned
void ACSDoor::BeginPlay()
{
	Super::BeginPlay();

	GetComponents(CachedAccessRequirementComponentsList);
	
	for(UCSAccessRequirementComponent* AccessRequirementComponent : CachedAccessRequirementComponentsList)
	{
		AccessRequirementComponent->OnAccessRequirementStatusChange.AddDynamic(this, &ACSDoor::OnAccessRequirementChange);
	}

}

void ACSDoor::OnAccessRequirementChange(bool bStatus)
{
	const bool bAllAccessRequirementsMet = AreAllAreAccessRequirementsMet();
	if(!bIsDoorOpen && bAllAccessRequirementsMet)
	{
		Open();
		bIsDoorOpen = true;
	}
	else if(bIsDoorOpen && !bAllAccessRequirementsMet)
	{
		Close();
		bIsDoorOpen = false;
	}

}

void ACSDoor::OnProximityStatusChange(bool bStatus)
{
	
}

