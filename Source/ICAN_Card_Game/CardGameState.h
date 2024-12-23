// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardGameState.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ICAN_CARD_GAME_API ACardFSMState : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartDelegate();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TickDelegate();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EndDelegate();

};
