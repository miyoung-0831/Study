// Fill out your copyright notice in the Description page of Project Settings.

#include "CRProtoGameMode.h"
#include "CRCharacter.h"
#include "CREnemyCharacter.h"

void ACRProtoGameMode::StartPlay()
{
	Super::StartPlay();
	
	if (GEngine)
	{
		// ����� �޽����� 5 �ʰ� ǥ���մϴ�.
		// "Ű" (ù ��° �μ�) ���� -1 �� �ϸ� �� �޽����� ���� ������Ʈ�ϰų� ���ΰ�ĥ �ʿ䰡 ������ ��Ÿ���ϴ�.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
	}

	SpawnCharacter(ACRCharacter::StaticClass(), FVector(400, -30, 120), FRotator(0, 0, 0));
	SpawnCharacter(ACREnemyCharacter::StaticClass(), FVector(-440, 110, 120), FRotator(0, 0, 0));
}

bool ACRProtoGameMode::SpawnCharacter(UClass* CharClass, FVector SpawnLocation, FRotator SpawnRotation)
{
	ACharacter* const ResultPawn = GetWorld()->SpawnActor<ACharacter>(CharClass, SpawnLocation, SpawnRotation);

	if (ResultPawn != nullptr)
	{
		ResultPawn->SpawnDefaultController();
		UE_LOG(LogClass, Log, TEXT("Character Spawn Seccess."));
		return true;
	}

	UE_LOG(LogClass, Log, TEXT("Character Spawn Fail..."));

	return false;
}


