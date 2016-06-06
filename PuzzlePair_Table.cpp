// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleProject.h"
#include "PuzzlePair_Table.h"


// Sets default values
APuzzlePair_Table::APuzzlePair_Table()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create scene component and replace as root
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	//Create static mesh and attach to the root
	VisibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleMesh"));
	VisibleMesh->AttachTo(RootComponent);
	
	//Create trigger boxes and attach to the mesh
	TriggerBox1 = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox1"));
	TriggerBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox2"));
	TriggerBox1->AttachTo(VisibleMesh);
	TriggerBox2->AttachTo(VisibleMesh);

}


// Called when the game starts or when spawned
void APuzzlePair_Table::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzlePair_Table::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool APuzzlePair_Table::getTrigger1()
{
	return Trigger1;
}

bool APuzzlePair_Table::getTrigger2()
{
	return Trigger2;
}

void APuzzlePair_Table::setTrigger1(bool truefalse)
{
	Trigger1 = truefalse;
}

void APuzzlePair_Table::setTrigger2(bool truefalse)
{
	Trigger2 = truefalse;
}
