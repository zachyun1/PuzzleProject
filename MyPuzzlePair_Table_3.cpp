// Copyright Zach Yun

#include "PuzzleProject.h"
#include "MyPuzzlePair_Table_3.h"

AMyPuzzlePair_Table_3::AMyPuzzlePair_Table_3()
{
	TriggerBox1->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_3::OnInteract1);
	TriggerBox2->OnComponentBeginOverlap.AddDynamic(this, &AMyPuzzlePair_Table_3::OnInteract2);
	TriggerBox1->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_3::OverlapEnd1);
	TriggerBox2->OnComponentEndOverlap.AddDynamic(this, &AMyPuzzlePair_Table_3::OverlapEnd2);
}

void AMyPuzzlePair_Table_3::OnInteract1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!(OtherComp->ComponentHasTag("Piece5")))
	{
		count1++;
		CorrectPiece5.Broadcast(false);
	}

	if (OtherComp->ComponentHasTag("Piece5"))
	{
		setTrigger1(true);
		if (count1 == 0)
		{
			CorrectPiece5.Broadcast(true);
		}
	}
}

//Triggers if the correct puzzle piece is place in trigger 2 volume
void AMyPuzzlePair_Table_3::OnInteract2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!(OtherComp->ComponentHasTag("Piece6")))
	{
		count2++;
		CorrectPiece6.Broadcast(false);
	}

	if (OtherComp->ComponentHasTag("Piece6"))
	{
		setTrigger1(true);
		if (count2 == 0)
		{
			CorrectPiece6.Broadcast(true);
		}
	}
}

void AMyPuzzlePair_Table_3::OverlapEnd1(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece5"))
	{
		count1--;
		if (count1 == 0)
		{
			count1++;
			CorrectPiece5.Broadcast(getTrigger1());
		}
	}
	if (OtherComp->ComponentHasTag("Piece5"))
	{
		setTrigger1(false);
		CorrectPiece5.Broadcast(false);
	}
}

void AMyPuzzlePair_Table_3::OverlapEnd2(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	if (!OtherComp->ComponentHasTag("Piece6"))
	{
		count2--;
		if (count2 == 0)
		{
			count2++;
			CorrectPiece6.Broadcast(getTrigger2());
		}
	}
	if (OtherComp->ComponentHasTag("Piece6"))
	{
		setTrigger2(false);
		CorrectPiece6.Broadcast(false);
	}
}

