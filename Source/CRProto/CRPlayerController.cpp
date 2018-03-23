// Fill out your copyright notice in the Description page of Project Settings.

#include "CRPlayerController.h"
#include "CRProtoGameMode.h"

void ACRPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using ACRPlayerController SetupInputComponent"));
	//}
	InputComponent->BindAction("MouseLeftClicked", IE_Pressed, this, &ACRPlayerController::OnMouseLeftButttonClick);
}

void ACRPlayerController::OnMouseLeftButttonClick()
{
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using ACRPlayerController OnMouseLeftButttonClick"));
	//}
	//UE_LOG(LogClass, Log, TEXT("OnMouseLeftButttonClick"));

	//ACRProtoGameMode* GameMode = (GetWorld() != NULL ? (ACRProtoGameMode*) GetWorld()->GetAuthGameMode() : NULL);

	//if (GameMode != NULL)
	//{
	//	FVector mouseLocation, mouseDirection;
	//	DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

	//	mouseLocation.Z = 200;
	//	UE_LOG(LogClass, Log, TEXT("Deproject :: Mouse Location %f, %f, %f"), mouseLocation.X, mouseDirection.Y, mouseLocation.Z);

	//	if (GEngine)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Deproject :: Mouse Location %f, %f, %f"), mouseLocation.X, mouseDirection.Y, mouseLocation.Z));
	//	}

	//	float LocationX, LocationY;
	//	GetMousePosition(LocationX, LocationY);

	//	UE_LOG(LogClass, Log, TEXT("GetMousePosition :: Mouse Location %f, %f"), LocationX, LocationY);
	//	if (GEngine)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("GetMousePosition :: Mouse Location %f, %f"), LocationX, LocationY));
	//	}
	//	const FVector spawnLoc(LocationX, LocationY, 200);
	//	GameMode->SpawnCharacter(mouseLocation);
	//}
}
