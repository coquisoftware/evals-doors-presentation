// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKeyInventoryItem.h"


// Sets default values
ACSKeyInventoryItem::ACSKeyInventoryItem()
{
	
}

void ACSKeyInventoryItem::Interact(AdoorsCharacter* InstigatorPawn)
{
	ICSInteractableInterface::Interact(InstigatorPawn);
	
}

// Called when the game starts or when spawned
void ACSKeyInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

