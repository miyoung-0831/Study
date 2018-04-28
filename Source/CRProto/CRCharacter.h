// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CRCharacter.generated.h"

UCLASS()
class CRPROTO_API ACRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
		void StartAttack();
	UFUNCTION()
		void StopAttack();

	UFUNCTION(BlueprintCallable, Category = "State")
		bool IsAttack() const;

	UFUNCTION(BlueprintCallable, Category = "State")
		bool IsDead() const;

	UFUNCTION()
		void AddDamage(int damage);
	
	UFUNCTION()
		int GetHealth();
	UFUNCTION()
		int GetPower();
	UFUNCTION()
	void Fire();

public:
	UPROPERTY(EditAnyWhere, Category = Behavior)
		class UBehaviorTree* BotBehavior;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
		class UCapsuleComponent* Body;

	UPROPERTY(EditAnywhere, Category = "TeamIndex")
		uint8 TeamIndex;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ACRProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;
private:
	UFUNCTION()
		void OnDie();

protected:
	bool mIsAttack : 1;	
	float WalkSpeed;
	int mHealth;
	int mPower;
	bool mIsDead : 1;
};
