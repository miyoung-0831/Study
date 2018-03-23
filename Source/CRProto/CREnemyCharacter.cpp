// Fill out your copyright notice in the Description page of Project Settings.

#include "CREnemyCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ACREnemyCharacter::ACREnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TeamIndex = 1;
	mPower = 8;
}

// Called when the game starts or when spawned
void ACREnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACREnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACREnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

