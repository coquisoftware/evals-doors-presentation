// Fill out your copyright notice in the Description page of Project Settings.


#include "CSJumpObjectiveAccessRequirementComponent.h"

#include "doorsCharacter.h"


// Sets default values for this component's properties
UCSJumpObjectiveAccessRequirementComponent::UCSJumpObjectiveAccessRequirementComponent()
{
	

	// ...
}

bool UCSJumpObjectiveAccessRequirementComponent::HasRequirementBeenMet_Implementation() const
{
	return NumPlayerJumps >= NumJumpsNeeded;
}


// Called when the game starts
void UCSJumpObjectiveAccessRequirementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	AdoorsCharacter* DoorsCharacter = Cast<AdoorsCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	DoorsCharacter->OnPlayerJump.AddDynamic(this, &UCSJumpObjectiveAccessRequirementComponent::OnPlayerJump );
	
	
	
	
}

void UCSJumpObjectiveAccessRequirementComponent::OnPlayerJump()
{
	++NumPlayerJumps;
}



