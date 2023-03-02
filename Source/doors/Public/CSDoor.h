// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSInteractableInterface.h"
#include "CSKeyInventoryItem.h"
#include "GameFramework/Actor.h"
#include "CSDoor.generated.h"

class UCSAccessRequirementComponent;
class ACSTriggerBox;


UENUM(BlueprintType)
enum EDoorUnlockBehavior : int
{
	AutoOpenUponUnlock,
	OpenUponProximity,
	OpenUponInteract,
};


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
	virtual ACSTriggerBox* GetTriggerBoxVolume() override;

	UFUNCTION(BlueprintImplementableEvent)
	void Open();
	
	UFUNCTION(BlueprintImplementableEvent)
	void Close();

	UFUNCTION()
	void Interact(AdoorsCharacter* InstigatorPawn);
	
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


	// None of these properties below are implemented, just laying out flags design would like to see for feedback
	UPROPERTY(EditAnywhere, Category=DoorConfig)
	TEnumAsByte<EDoorUnlockBehavior> DoorUnlockOpenBehavior;

	UPROPERTY(EditAnywhere, Category=DoorConfig)
	bool bRequireInventoryItem;

	UPROPERTY(EditAnywhere, Category=DoorConfig, meta=(EditCondition="bRequireInventoryItem"))
	TMap< TSubclassOf<ACSKeyInventoryItem> , int > RequiredInventoryItems; 

	UPROPERTY(EditAnywhere, Category=DoorConfig)
	bool bAutoClose;

	UPROPERTY(EditAnywhere, Category=DoorConfig, meta=(EditCondition="bAutoClose"))
	float AutoCloseTimeDuration;

	
	

	
protected:
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsDoorOpen;

	

private:

	
	
};


