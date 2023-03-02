// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSCharacterInteractionComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DOORS_API UCSCharacterInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCSCharacterInteractionComponent();

	UFUNCTION()
	void Interact();

	UFUNCTION(BlueprintCallable)
	void SetInstigatingActor(AActor* InActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractableObjectDetectStatus, bool, bIsAroundInteractable);
	UPROPERTY(BlueprintAssignable)
	FOnInteractableObjectDetectStatus OnInteractableObjectDetectStatus;
	
	
	
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(Transient)
	AActor* InterfacableActor;

};
