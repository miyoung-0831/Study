// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CRAIController.generated.h"

/**
 * 
 */
UCLASS()
class CRPROTO_API ACRAIController : public AAIController
{
	GENERATED_BODY()

public:
	ACRAIController();

	virtual void Possess(APawn* inPawn) override;
	
	void SetEnemy(class APawn* InPawn);

	virtual void UpdateControlRotation(float DeltaTime, bool bUpdatePawn = true);
	
	UFUNCTION(BlueprintCallable, Category = Behavior)
		void AttackEnemy();

	class ACRCharacter* GetEnemy() const;

	uint8 EnemyKeyID;

private:
	UPROPERTY(transient)
		class UBlackboardComponent* BlackboardComp;
	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorComp;
};
