// Fill out your copyright notice in the Description page of Project Settings.


#include "CardData.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UCardData::UCardData()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCardData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCardData, Name);
	DOREPLIFETIME(UCardData, Strength);
	DOREPLIFETIME(UCardData, Placement);
}

