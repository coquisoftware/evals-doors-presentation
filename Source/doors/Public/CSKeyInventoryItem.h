// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSInteractableInterface.h"
#include "GameFramework/Actor.h"
#include "CSKeyInventoryItem.generated.h"

UCLASS()
class DOORS_API ACSKeyInventoryItem : public AActor, public ICSInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACSKeyInventoryItem();

	UFUNCTION()
	virtual void Interact(AdoorsCharacter* InstigatorPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
};
