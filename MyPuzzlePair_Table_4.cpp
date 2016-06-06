// Copyright Zach Yun

#include "PuzzleProject.h"
#include "MyPuzzlePair_Table_4.h"

AMyPuzzlePair_Table_4::AMyPuzzlePair_Table_4()
{
	TriggerBox1->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_4::OnInteract1);
	TriggerBox2->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_4::OnInteract2);
	TriggerBox1->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_4::OverlapEnd1);
	TriggerBox2->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_4::OverlapEnd2);
}

void AMyPuzzlePair_Table_4::OnInteract1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherComp->ComponentHasTag("Piece7"))
	{
		count1++;
		CorrectPiece7.Broadcast(false);
	}
	if (OtherComp->ComponentHasTag("Piece7"))
	{
		setTrigger2(true);
		if (count1 == 0)
		{
			CorrectPiece7.Broadcast(true);
		}
	}
}

//Triggers if the correct puzzle piece is place in trigger 2 volume
void AMyPuzzlePair_Table_4::OnInteract2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherComp->ComponentHasTag("Piece8"))
	{
		count2++;
		CorrectPiece8.Broadcast(false);
	}
	if (OtherComp->ComponentHasTag("Piece8"))
	{
		setTrigger2(true);
		if (count2 == 0)
		{
			CorrectPiece8.Broadcast(true);
		}
	}
}

void AMyPuzzlePair_Table_4::OverlapEnd1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece7"))
	{
		count1--;
		if (count1 == 0)
		{
			count1++;
			CorrectPiece7.Broadcast(getTrigger1());
		}
	}
	if (OtherComp->ComponentHasTag("Piece7"))
	{
		setTrigger1(false);
		CorrectPiece7.Broadcast(false);
	}
}

void AMyPuzzlePair_Table_4::OverlapEnd2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece8"))
	{
		count2--;
		if (count2 == 0)
		{
			count2++;
			CorrectPiece8.Broadcast(getTrigger2());
		}
	}
	if (OtherComp->ComponentHasTag("Piece8"))
	{
		setTrigger2(false);
		CorrectPiece8.Broadcast(false);
	}
}


