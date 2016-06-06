// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PuzzlePair_Table.h"
#include "MyPuzzlePair_Table_1.generated.h"

/**
*
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece1, bool, Trigger1Pressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece2, bool, Trigger2Pressed);

UCLASS()
class PUZZLEPROJECT_API AMyPuzzlePair_Table_1 : public APuzzlePair_Table
{
	GENERATED_BODY()

public:
	AMyPuzzlePair_Table_1();

	UFUNCTION()
	void OnInteract1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnInteract2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex);

	UFUNCTION()
	void OverlapEnd2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex);

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FOnCorrectPiece1 CorrectPiece1;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FOnCorrectPiece2 CorrectPiece2;

};