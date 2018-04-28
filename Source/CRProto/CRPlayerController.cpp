// Fill out your copyright notice in the Description page of Project Settings.

#include "CRPlayerController.h"
#include "CRProtoGameMode.h"
#include "CRCharacter.h"

void ACRPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using ACRPlayerController SetupInputComponent"));
	//}
	InputComponent->BindAction("MouseLeftClicked", IE_Pressed, this, &ACRPlayerController::OnMouseLeftButttonClick);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACRPlayerController::Fire);
}

void ACRPlayerController::OnMouseLeftButttonClick()
{
	float LocationX, LocationY;
	GetMousePosition(LocationX, LocationY);

	FVector2D mouseLoc(LocationX, LocationY);
	FHitResult hitResult;
	GetHitResultAtScreenPosition(mouseLoc, ECC_WorldStatic, false, hitResult);
	ACRProtoGameMode* GameMode = (GetWorld() != NULL ? (ACRProtoGameMode*)GetWorld()->GetAuthGameMode() : NULL);

	if (hitResult.bBlockingHit)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using ACRPlayerController OnMouseLeftButttonClick"));
		}
		if (GameMode != NULL)
		{
			GameMode->SpawnCharacter(ACRCharacter::StaticClass(), hitResult.ImpactPoint + FVector(0, 0, 120), FRotator(0, 0, 0));
		}
	}
}

void ACRPlayerController::Fire()
{
	for (FConstPawnIterator Iterator = GetWorld()->GetPawnIterator(); Iterator; ++Iterator)
	{
		ACRCharacter* CRChar = Cast<ACRCharacter>(Iterator->Get());
		CRChar->Fire();
	}
}