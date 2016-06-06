// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleProject.h"
#include "MyPuzzlePair_Table_1.h"

AMyPuzzlePair_Table_1::AMyPuzzlePair_Table_1()
{
	TriggerBox1->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_1::OnInteract1);
	TriggerBox2->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_1::OnInteract2);
	TriggerBox1->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_1::OverlapEnd1);
	TriggerBox2->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_1::OverlapEnd2);
}

void AMyPuzzlePair_Table_1::OnInteract1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!(OtherComp->ComponentHasTag("Piece1")))
	{
		count1++;
		CorrectPiece1.Broadcast(false);
	}

	if (OtherComp->ComponentHasTag("Piece1"))
	{
		setTrigger1(true);
		if (count1 == 0)
		{
			CorrectPiece1.Broadcast(true);
		}
	}
}

//Triggers if the correct puzzle piece is place in trigger 2 volume
void AMyPuzzlePair_Table_1::OnInteract2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherComp->ComponentHasTag("Piece2"))
	{
		count2++;
		CorrectPiece2.Broadcast(false);
	}
	if (OtherComp->ComponentHasTag("Piece2"))
	{
		setTrigger2(true);
		if (count2 == 0)
		{
			CorrectPiece2.Broadcast(true);
		}
	}
}

void AMyPuzzlePair_Table_1::OverlapEnd1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece1"))
	{
		count1--;
		if (count1 == 0)
		{
			count1++;
			CorrectPiece1.Broadcast(getTrigger1());
		}
	}
	if (OtherComp->ComponentHasTag("Piece1"))
	{
		setTrigger1(false);
		CorrectPiece1.Broadcast(false);
	}
}

void AMyPuzzlePair_Table_1::OverlapEnd2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece2"))
	{
		count2--;
		if (count2 == 0)
		{
			count2++;
			CorrectPiece2.Broadcast(getTrigger2());
		}
	}

	if (OtherComp->ComponentHasTag("Piece2"))
	{
		setTrigger2(false);
		CorrectPiece2.Broadcast(false);
	}
}