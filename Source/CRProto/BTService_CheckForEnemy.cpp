// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_CheckForEnemy.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "CRCharacter.h"
#include "CRAIController.h"

UBTService_CheckForEnemy::UBTService_CheckForEnemy()
{
	bCreateNodeInstance = true;
}

void UBTService_CheckForEnemy::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	ACRAIController* PC = Cast<ACRAIController>(OwnerComp.GetAIOwner());
	ACRCharacter* ownerChar = NULL;

	if (PC)
		ownerChar = Cast<ACRCharacter>(PC->GetPawn());

	if (ownerChar)
	{
		for (FConstPawnIterator Iterator = GetWorld()->GetPawnIterator(); Iterator; ++Iterator)
		{
			ACRCharacter* EnemyChar = Cast<ACRCharacter>(Iterator->Get());
			if (ownerChar->TeamIndex != EnemyChar->TeamIndex)
			{
				PC->SetEnemy(EnemyChar);
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Enemy is here."));
			}
		}
	}
}
