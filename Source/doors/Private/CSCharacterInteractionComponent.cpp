// Fill out your copyright notice in the Description page of Project Settings.


#include "CSCharacterInteractionComponent.h"

#include "CSInteractableInterface.h"
#include "doorsCharacter.h"


// Sets default values for this component's properties
UCSCharacterInteractionComponent::UCSCharacterInteractionComponent()
{
	InterfacableActor = nullptr;
}


// Called when the game starts
void UCSCharacterInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UCSCharacterInteractionComponent::Interact()
{
	if(InterfacableActor != nullptr && InterfacableActor->Implements<UCSInteractableInterface>())
	{
		AdoorsCharacter* DoorsCharacter = Cast<AdoorsCharacter>(GetOwner());

		if(ICSInteractableInterface* Interface = Cast<ICSInteractableInterface>(InterfacableActor))
		{
			Interface->Interact(DoorsCharacter);
		}
		
	}
}

void UCSCharacterInteractionComponent::SetInterfacableActor(AActor* InActor)
{
	InterfacableActor = InActor;
	OnInteractableObjectDetectStatus.Broadcast(InterfacableActor != nullptr);
}




