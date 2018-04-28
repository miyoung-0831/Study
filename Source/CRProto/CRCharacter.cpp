// Fill out your copyright notice in the Description page of Project Settings.

#include "CRCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "BehaviorTree/BehaviorTree.h"
#include "CRAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "CRProjectile.h"


// Sets default values
ACRCharacter::ACRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> AssignableMesh(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	
	GetMesh()->RelativeLocation = FVector(0.0f, 0.0f, -88.0f);
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));
	GetMesh()->SetSkeletalMesh(AssignableMesh.Object);

	static ConstructorHelpers::FObjectFinder<UClass> AnimBP(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP_C'"));
	
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetAnimInstanceClass(AnimBP.Object);

	AIControllerClass = ACRAIController::StaticClass();

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviorTree(TEXT("BehaviorTree'/Game/Blueprints/EnemyBT.EnemyBT'"));
	BotBehavior = BehaviorTree.Object;
	
	static ConstructorHelpers::FObjectFinder<UClass> ProjectileBP(TEXT("Blueprint'/Game/Blueprints/BP_Projectile.BP_Projectile_C'"));
	ProjectileClass = ProjectileBP.Object;

	MuzzleOffset.X = 100;
	MuzzleOffset.Y = 0;
	MuzzleOffset.Z = 0;

	TeamIndex = 0;
	mHealth = 200;
	mPower = 10;

	WalkSpeed = 200.f;
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	mIsDead = false;
}

void ACRCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
// Called when the game starts or when spawned
void ACRCharacter::BeginPlay()
{
	Super::BeginPlay();

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using CRCharacter."));
	//}

	UE_LOG(LogClass, Log, TEXT("ACRCraracter :: location %f, %f, %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}

// Called every frame
void ACRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACRCharacter::AddDamage(int damage)
{
	mHealth -= damage;
	
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("AddDamage : %d"), damage));
	//}

	if (mHealth <= 0)
	{
		OnDie();
	}
}

int ACRCharacter::GetHealth()
{
	return mHealth;
}

void ACRCharacter::OnDie()
{
	mIsDead = true;
	SetLifeSpan(2.f);
}

void ACRCharacter::StartAttack()
{
	mIsAttack = true;
}

void ACRCharacter::StopAttack()
{
	mIsAttack = false;
}

bool ACRCharacter::IsAttack() const
{
	return mIsAttack;
}

bool ACRCharacter::IsDead() const
{
	return mIsDead;
}

int ACRCharacter::GetPower()
{
	return mPower;
}
void ACRCharacter::Fire()
{
	if (ProjectileClass)
	{
		FVector loc;
		FRotator rot;

		GetActorEyesViewPoint(loc, rot);

		// MuzzleOffset 을 카메라 스페이스에서 월드 스페이스로 변환합니다.
		FVector MuzzleLocation = loc + FTransform(rot).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = rot;
		// 조준을 약간 윗쪽으로 올려줍니다.
		MuzzleRotation.Pitch += 10.0f;
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			ACRProjectile* Projectile = World->SpawnActor<ACRProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// 발사 방향을 알아냅니다.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}