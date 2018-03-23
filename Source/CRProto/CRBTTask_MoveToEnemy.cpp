// Fill out your copyright notice in the Description page of Project Settings.

#include "CRBTTask_MoveToEnemy.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "CRAIController.h"
#include "CRCharacter.h"

EBTNodeResult::Type UCRBTTask_MoveToEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACRAIController* PC = Cast<ACRAIController>(OwnerComp.GetAIOwner());

	ACRCharacter* Enemy = Cast<ACRCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(PC->EnemyKeyID));

	if (Enemy)
	{
		PC->MoveToActor(Enemy, 80.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	EBTNodeResult::Failed;
}

