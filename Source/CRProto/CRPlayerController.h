// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CRPROTO_API ACRPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void SetupInputComponent();

private:
	void OnMouseLeftButttonClick();
};
