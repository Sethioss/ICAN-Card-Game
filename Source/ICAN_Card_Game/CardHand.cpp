// Fill out your copyright notice in the Description page of Project Settings.


#include "CardHand.h"
#include "Card.h"

// Sets default values
ACardHand::ACardHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardHand::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACardHand::DisplayHand()
{
	for (int i = 0; i < CardsInHands.Num(); ++i)
	{
		FVector ActorLocation = GetActorLocation();

		FVector Og;
		FVector BoxExtent;

		CardsInHands[i]->GetActorBounds(true, Og, BoxExtent);

		FVector SpawnLocation(ActorLocation.X, ActorLocation.Y + ((i * (BoxExtent.Y * 2.5f))), ActorLocation.Z + (i * 0.001f));
		FRotator SpawnRotation(90.0f, 0.0f, 0.0f);

		Cast<AActor>(CardsInHands[i])->SetActorLocation(SpawnLocation);
		Cast<AActor>(CardsInHands[i])->SetActorRotation(SpawnRotation);
	}
}

// Called every frame
void ACardHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

