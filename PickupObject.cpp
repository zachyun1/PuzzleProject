// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleProject.h"
#include "PickupObject.h"


// Sets default values
APickupObject::APickupObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APickupObject::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

