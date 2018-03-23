// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CRCharacter.h"
#include "CREnemyCharacter.generated.h"

UCLASS()
class CRPROTO_API ACREnemyCharacter : public ACRCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACREnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
