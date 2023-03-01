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

	UFUNCTION(BlueprintPure)
	virtual bool HasRequirementBeenMet() const override;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void CheckAndNotifyAccessRequirementStatusChange(bool bNewStatus);

public:

	UPROPERTY(Transient)
	ACSTriggerBox* TriggerVolume;

private:

	UPROPERTY()
	bool bIsCharacterInTriggerVolume;
	

};
