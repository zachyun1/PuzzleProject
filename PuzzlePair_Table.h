// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PuzzlePair_Table.generated.h"

UCLASS()
class PUZZLEPROJECT_API APuzzlePair_Table : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzlePair_Table();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintPure, Category = "PuzzleTable")
		bool getTrigger1();

	UFUNCTION(BlueprintCallable, Category = "PuzzleTable")
		void setTrigger1(bool truefalse);

	UFUNCTION(BlueprintPure, Category = "PuzzleTable")
		bool getTrigger2();

	UFUNCTION(BlueprintCallable, Category = "PuzzleTable")
		void setTrigger2(bool truefalse);

protected:

	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox1;

	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox2;

	bool Trigger1;
	bool Trigger2;
	int count1;
	int count2;



private:

	UPROPERTY(EditAnywhere)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* VisibleMesh;

};
