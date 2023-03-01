// Fill out your copyright notice in the Description page of Project Settings.


#include "doors/Public/CSDoor.h"

#include "CSAccessRequirementComponent.h"


// Sets default values
ACSDoor::ACSDoor()
{
}

bool ACSDoor::AreAllAreAccessRequirementsMet() const
{
	bool bResult = true;

	TArray<UCSAccessRequirementComponent*> AccessRequirementComponentsList;
	GetComponents(AccessRequirementComponentsList);

	for(const UCSAccessRequirementComponent* AccessRequirementComponent : AccessRequirementComponentsList)
	{
		if(!AccessRequirementComponent->RequirementHasBeenMet())
		{
			bResult = false;
			break;
		}
	}

	return bResult;
	
}

// Called when the game starts or when spawned
void ACSDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


