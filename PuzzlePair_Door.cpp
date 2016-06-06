// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleProject.h"
#include "PuzzlePair_Door.h"


// Sets default values
APuzzlePair_Door::APuzzlePair_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//AMyPuzzlePair_Table_1* Table1 = Cast<AMyPuzzlePair_Table_1>();
	//if (Table1 = IsValid())
	//{
	//	Table1->CorrectPiece1.AddDynamic(this, //Function here)
	//}
	//

}

// Called when the game starts or when spawned
void APuzzlePair_Door::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzlePair_Door::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

