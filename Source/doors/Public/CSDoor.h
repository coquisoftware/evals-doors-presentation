// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSInteractableInterface.h"
#include "GameFramework/Actor.h"
#include "CSDoor.generated.h"

class UCSAccessRequirementComponent;
class ACSTriggerBox;


// UENUM(BlueprintType)
// enum EDoorUnlockBehavior : uint8
// {
// 	AutoOpen,
// 	OpenUponInteract	
// };


UCLASS()
class DOORS_API ACSDoor : public AActor, public ICSInteractableInterface
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	ACSDoor();

	UFUNCTION(BlueprintPure)
	bool AreAllAreAccessRequirementsMet() const;

	UFUNCTION(BlueprintPure)
	FText GetDoorLabel() const;

	UFUNCTION(BlueprintCallable)
	ACSTriggerBox* GetTriggerBoxVolume();

	UFUNCTION(BlueprintImplementableEvent)
	void Open();
	
	UFUNCTION(BlueprintImplementableEvent)
	void Close();

	UFUNCTION()
	void Interact(APawn* InstigatorPawn);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnAccessRequirementChange(bool bStatus);

	UFUNCTION()
	void OnProximityStatusChange(bool bStatus);

public:

	UPROPERTY(EditAnywhere)
	FText DoorLabel;
	
protected:
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsDoorOpen;

	UPROPERTY(BlueprintReadOnly)
	ACSTriggerBox* TriggerBoxVolume; 

private:

	TArray<UCSAccessRequirementComponent*> CachedAccessRequirementComponentsList;
	
};


