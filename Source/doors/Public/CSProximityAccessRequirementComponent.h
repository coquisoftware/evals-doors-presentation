// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSAccessRequirementComponent.h"
#include "Components/ActorComponent.h"
#include "CSProximityAccessRequirementComponent.generated.h"

class ACSTriggerBox;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSProximityAccessRequirementComponent : public UCSAccessRequirementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSProximityAccessRequirementComponent();

	virtual bool HasRequirementBeenMet_Implementation() const override;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	virtual void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:

	UPROPERTY(Transient)
	ACSTriggerBox* TriggerVolume;

	

private:

	UPROPERTY()
	bool bIsCharacterInTriggerVolume;
	

};
