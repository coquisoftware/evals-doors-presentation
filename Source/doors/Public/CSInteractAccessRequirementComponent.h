// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSProximityAccessRequirementComponent.h"
#include "CSInteractAccessRequirementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSInteractAccessRequirementComponent : public UCSProximityAccessRequirementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSInteractAccessRequirementComponent();

	virtual bool HasRequirementBeenMet_Implementation() const override;
	
	UFUNCTION(BlueprintCallable)
	void SetInteractStatus(bool bStatus);

	UFUNCTION(BlueprintCallable)
	void ToggleInteractStatus();

	virtual void OnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) override;

	virtual void OnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor) override;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	bool bHasBeenInteractedWith;


};

