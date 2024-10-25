// Fill out your copyright notice in the Description page of Project Settings.
#include "ScoreCalculator.h"
#include "Card.h"
#include "ScoreBonus.h"
#include "ScoreBonusOperand.h"
#include "ScoreRule.h"

UScoreCalculator* UScoreCalculator::Instance = nullptr;

// Sets default values for this component's properties
UScoreCalculator::UScoreCalculator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UScoreCalculator* UScoreCalculator::GetInstance()
{
	return Instance;
}

int UScoreCalculator::CalculateScore(TArray<ACard*> PlayedCards)
{
	float Score = 0.0f;
	
	for(int i = 0; i < PlayedCards.Num(); i++)
	{
		Score += PlayedCards[i]->GetCardDataComp()->Value;
	}
	UE_LOG(LogTemp, Warning, TEXT("Current Score: %f"), Score);
	
	for(int i = 0; i < MyRules.Num(); i++)
	{
		UScoreRule* CurRule = MyRules[i].Rule.GetDefaultObject();
		if(CurRule && CurRule->bValidateRule(PlayedCards))
		{
			UE_LOG(LogTemp, Warning, TEXT("Rule %s was validated"), *CurRule->GetName());

			if(MyRules[i].bDefiniteValue)
			{
				UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
				UE_LOG(LogTemp, Warning, TEXT("Applying definite %f bonus"), MyRules[i].DefiniteValue);
				Score = CurOperand->Apply(Score, MyRules[i].DefiniteValue);
			}
			else
			{
				if(MyRules[i].Bonus)
				{
					UScoreBonus* CurBonus = MyRules[i].Bonus.GetDefaultObject();
					if(CurBonus)
					{
						float FinalBonusValue = CurBonus->SetBonusValue(CurBonus->BonusValue, PlayedCards);
					
						UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
						UE_LOG(LogTemp, Warning, TEXT("Applying %s bonus (%f)"), *CurBonus->GetName(), FinalBonusValue);
						Score = CurOperand->Apply(Score, FinalBonusValue);
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No bonus for rule %s was found!"), *CurRule->GetName());
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Rule %s was invalidated!!!"), *CurRule->GetName());
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Final Score: %f"), Score);
	return FMath::CeilToInt(Score);
}


// Called when the game starts
void UScoreCalculator::BeginPlay()
{
	Super::BeginPlay();
	
	if(!Instance)
	{
		Instance = this;
	}
	
}

void UScoreCalculator::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if(Instance)
	{
		Instance->RemoveFromRoot();
		Instance = nullptr;
	}
}


// Called every frame
void UScoreCalculator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

