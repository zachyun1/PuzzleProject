// Copyright Zach Yun

#pragma once

#include "PuzzleTable/PuzzlePair_Table.h"
#include "MyPuzzlePair_Table_3.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece5, bool, Trigger1Pressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectPiece6, bool, Trigger2Pressed);

UCLASS()
class PUZZLEPROJECT_API AMyPuzzlePair_Table_3 : public APuzzlePair_Table
{
	GENERATED_BODY()

public:
	AMyPuzzlePair_Table_3();

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
	FOnCorrectPiece5 CorrectPiece5;

	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	FOnCorrectPiece6 CorrectPiece6;


};
