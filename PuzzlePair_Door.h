// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyPuzzlePair_Table_1.h"
#include "PuzzlePair_Door.generated.h"

UCLASS()
class PUZZLEPROJECT_API APuzzlePair_Door : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzlePair_Door();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


protected:
	bool bIsLocked;

	
	
};
