// Fill out your copyright notice in the Description page of Project Settings.


#include "ESCCharacterHand.h"
#include "MotionControllerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AESCCharacterHand::AESCCharacterHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
}

// Called when the game starts or when spawned
void AESCCharacterHand::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AESCCharacterHand::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AESCCharacterHand::ActorEndOverlap);
	
}

// Called every frame
void AESCCharacterHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AESCCharacterHand::PairController(AESCCharacterHand* Hand)
{
	OtherController = Hand;
	OtherController->OtherController = this;
}

void AESCCharacterHand::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}

bool AESCCharacterHand::CheckSearch() const
{
	TArray<AActor*> OverlappingActors;

	GetOverlappingActors(OverlappingActors);

	for (AActor* OverlappingActor : OverlappingActors)
	{
		if (OverlappingActor->ActorHasTag(TEXT("Searchable")))
		{
			return true;
		}
	}
	return false;
}

void AESCCharacterHand::Search()
{
	if (!CheckSearch()) return;

	if (!bIsSearching)
	{
		bIsSearching = true;

		OtherController->bIsSearching = false;
		UE_LOG(LogTemp, Warning, TEXT("Searching..."));
	}
}

void AESCCharacterHand::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (CheckSearch() || OverlappedActor == OtherController)
	{
		APawn* Pawn = Cast<APawn>(GetAttachParentActor());

		if (Pawn != nullptr)
		{
			APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
			if (PC != nullptr)
			{
				PC->PlayHapticEffect(RumbleEffect, MotionController->GetTrackingSource());
			}
		}
	}
}

void AESCCharacterHand::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	bCanSearch = CheckSearch();
}
