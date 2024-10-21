// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSlotComponent.h"
#include "CardCollection.h"
#include "CardCollectionsManager.h"

UCardSlotComponent::UCardSlotComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCardSlotComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CollectionManager = UCardCollectionsManager::GetInstance();
}

void UCardSlotComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UCardSlotComponent::Interact(ACard* Card) const
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with slot %i!"), ID);
	ACardCollection* OwnerCollection = Cast<ACardCollection>(GetOwner());

	if(OwnerCollection)
	{
		const bool bTransferSucceeded = CollectionManager->MoveBetweenCollections(CollectionManager->Hand, OwnerCollection, Card, ID);
		OwnerCollection->UpdateCollectionVisuals();
		CollectionManager->DeselectHand();

		return bTransferSucceeded;
		
	}
	return false;
}
