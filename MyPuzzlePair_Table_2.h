// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PuzzlePair_Table.h"
#include "MyPuzzlePair_Table_2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece3, bool, Trigger1Pressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece4, bool, Trigger2Pressed);

UCLASS()
class PUZZLEPROJECT_API AMyPuzzlePair_Table_2 : public APuzzlePair_Table
{
	GENERATED_BODY()
	
public:
	AMyPuzzlePair_Table_2();

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
	FOnCorrectPiece3 CorrectPiece3;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FOnCorrectPiece4 CorrectPiece4;
	
	
};
