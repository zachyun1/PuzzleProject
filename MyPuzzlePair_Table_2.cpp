// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleProject.h"
#include "MyPuzzlePair_Table_2.h"

AMyPuzzlePair_Table_2::AMyPuzzlePair_Table_2()
{
	TriggerBox1->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_2::OnInteract1);
	TriggerBox2->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_2::OnInteract2);
	TriggerBox1->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_2::OverlapEnd1);
	TriggerBox2->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_2::OverlapEnd2);
}

void AMyPuzzlePair_Table_2::OnInteract1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherComp->ComponentHasTag("Piece3"))
	{
		count1++;
		CorrectPiece3.Broadcast(false);
	}
	if (OtherComp->ComponentHasTag("Piece3"))
	{
		setTrigger2(true);
		if (count1 == 0)
		{
			CorrectPiece3.Broadcast(true);
		}
	}
}

//Triggers if the correct puzzle piece is place in trigger 2 volume
void AMyPuzzlePair_Table_2::OnInteract2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherComp->ComponentHasTag("Piece4"))
	{
		count2++;
		CorrectPiece4.Broadcast(false);
	}
	if (OtherComp->ComponentHasTag("Piece4"))
	{
		setTrigger2(true);
		if (count2 == 0)
		{
			CorrectPiece4.Broadcast(true);
		}
	}
}

void AMyPuzzlePair_Table_2::OverlapEnd1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece3"))
	{
		count1--;
		if (count1 == 0)
		{
			count1++;
			CorrectPiece3.Broadcast(getTrigger1());
		}
	}
	if (OtherComp->ComponentHasTag("Piece3"))
	{
		setTrigger1(false);
		CorrectPiece3.Broadcast(false);
	}
}

void AMyPuzzlePair_Table_2::OverlapEnd2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece4"))
	{
		count2--;
		if (count2 == 0)
		{
			count2++;
			CorrectPiece4.Broadcast(getTrigger2());
		}
	}
	if (OtherComp->ComponentHasTag("Piece4"))
	{
		setTrigger2(false);
		CorrectPiece4.Broadcast(false);
	}
}


