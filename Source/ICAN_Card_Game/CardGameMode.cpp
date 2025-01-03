// Fill out your copyright notice in the Description page of Project Settings.
#include "CardGameMode.h"
#include "Net/UnrealNetwork.h"
#include "CardGameFSM.h"

void ACardGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ACardGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACardGameMode, Deck);
	DOREPLIFETIME(ACardGameMode, PlayedCards);
	DOREPLIFETIME(ACardGameMode, StateMachine);
}
