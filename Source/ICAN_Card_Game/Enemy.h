// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

class UStaticMeshComponent;
class UTextRenderComponent;

UCLASS(Blueprintable, BlueprintType)
class ICAN_CARD_GAME_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextRenderComponent> TextComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextRenderComponent> TextComponentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> EnemyMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
