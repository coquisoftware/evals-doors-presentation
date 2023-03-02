// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSInventoryComponent.generated.h"

class ACSKeyInventoryItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryListUpdate, ACSKeyInventoryItem*, Item);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSInventoryComponent();

	// Simply adds the provided item to the list
	void AddToInventory(ACSKeyInventoryItem* Item);

	// Delegate for notifying item added to the ist
	UPROPERTY()
	FOnInventoryListUpdate OnInventoryItemAdded;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Player inventory list
	TArray<ACSKeyInventoryItem*> InventoryItemList;

};
