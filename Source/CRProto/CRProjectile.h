// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRProjectile.generated.h"

UCLASS()
class CRPROTO_API ACRProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACRProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 구체 콜리전 컴포넌트
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionComponent;

	// 프로젝타일 무브먼트 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Movement)
		class UProjectileMovementComponent* ProjectileMovementComponent;

	void FireInDirection(const FVector& ShootDirection);
};
