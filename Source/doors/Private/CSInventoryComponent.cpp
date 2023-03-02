// Fill out your copyright notice in the Description page of Project Settings.


#include "CSInventoryComponent.h"


// Sets default values for this component's properties
UCSInventoryComponent::UCSInventoryComponent()
{
	
	// ...
}

void UCSInventoryComponent::AddToInventory(ACSKeyInventoryItem* Item)
{
	InventoryItemList.Push(Item);
}


// Called when the game starts
void UCSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}




