// Fill out your copyright notice in the Description page of Project Settings.


#include "doors/Public/CSDoor.h"


// Sets default values
ACSDoor::ACSDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACSDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACSDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

