// Fill out your copyright notice in the Description page of Project Settings.

#include "CRAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "CRCharacter.h"

ACRAIController::ACRAIController()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ACRAIController::Possess(APawn * inPawn)
{
	Super::Possess(inPawn);
	ACRCharacter* Char = Cast<ACRCharacter>(inPawn);

	if (Char && Char->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*Char->BotBehavior);
	}
}

void ACRAIController::SetEnemy(class APawn* InPawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValue<UBlackboardKeyType_Object>(EnemyKeyID, InPawn);
	}
}

void ACRAIController::UpdateControlRotation(float DeltaTime, bool bUpdatePawn)
{
	FVector FocalPoint = GetFocalPoint();

	if (!FocalPoint.IsZero() && GetPawn())
	{
		FVector Direction = FocalPoint - GetPawn()->GetActorLocation();
		FRotator NewControlRotation = Direction.Rotation();

		NewControlRotation.Yaw = FRotator::ClampAxis(NewControlRotation.Yaw);
		SetControlRotation(NewControlRotation);

		APawn* const P = GetPawn();
		if (P && bUpdatePawn)
		{
			P->FaceRotation(NewControlRotation, DeltaTime);
		}
	}
}

void ACRAIController::AttackEnemy()
{
	ACRCharacter* MyBot = Cast<ACRCharacter>(GetPawn());
	ACRCharacter* Enemy = GetEnemy();
	bool bCanAttack = false;

	if (MyBot->IsDead())
		return;

	if (Enemy)
	{
		const float Dist = (Enemy->GetActorLocation() - MyBot->GetActorLocation()).Size2D();
		if (Dist < 250)
		{
			bCanAttack = true;
		}
	}
	
	if (bCanAttack && Enemy->GetHealth() > 0)
	{
		MyBot->StartAttack();
		Enemy->AddDamage(MyBot->GetPower());
	}
	else
	{
		MyBot->StopAttack();
	}
}

class ACRCharacter* ACRAIController::GetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<ACRCharacter>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(EnemyKeyID));
	}
	
	return NULL;
}