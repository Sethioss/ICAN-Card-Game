// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSlotComponent.h"
#include "CardCollection.h"
#include "CardCollectionsManager.h"
#include "PlayedCardMat.h"
#include "CGGameState.h"
#include "Net/UnrealNetwork.h"

UCardSlotComponent::UCardSlotComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCardSlotComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCardSlotComponent, ID);
}
