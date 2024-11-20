// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedCardCollectionManager.h"
#include "ReplicatedCardCollection.h"

bool UReplicatedCardCollectionManager::SwapCard(UReplicatedCardData*& CardAID, UReplicatedCardData*& CardBID)
{
	if (CardAID && CardBID)
	{
		::Swap(CardAID, CardBID);
		return true;
	}
	return false;
}

bool UReplicatedCardCollectionManager::MoveBetweenCollections(UReplicatedCardCollection* A, UReplicatedCardCollection* B, UReplicatedCardData* CardData, const int IndexToMoveAt)
{
	bool Result = false;
	bool IsAnyCollectionInvalid = A->Elements.Num() <= 0 || (!B->bInfiniteCapacity && (B->Elements.Num() > B->MaxCapacity));
	if (IsAnyCollectionInvalid) { return false; }
	
	if (A && B && CardData)
	{
		Result |= A->RemoveCard(CardData);
		if (IndexToMoveAt < 0)
		{
			Result = Result && B->AddCard(CardData);
		}
		else
		{
			Result = Result && B->SetCard(CardData, IndexToMoveAt);
		}
		A->UpdateCollectionVisuals();
		B->UpdateCollectionVisuals();
	}
	return Result;
}
