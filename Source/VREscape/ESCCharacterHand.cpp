// Fill out your copyright notice in the Description page of Project Settings.


#include "ESCCharacterHand.h"
#include "MotionControllerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
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
	
}

// Called every frame
void AESCCharacterHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AESCCharacterHand::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}

