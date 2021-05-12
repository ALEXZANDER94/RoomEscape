// Fill out your copyright notice in the Description page of Project Settings.


#include "ESC_Character.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ESCCharacterHand.h"

// Sets default values
AESC_Character::AESC_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ESCCharacterRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CharacterRoot"));
	ESCCharacterRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(ESCCharacterRoot);

}

// Called when the game starts or when spawned
void AESC_Character::BeginPlay()
{
	Super::BeginPlay();
	
	RightHand = GetWorld()->SpawnActor<AESCCharacterHand>(ESCHandClass);
	if (RightHand != nullptr)
	{
		RightHand->AttachToComponent(ESCCharacterRoot, FAttachmentTransformRules::KeepRelativeTransform);
		RightHand->SetOwner(this);
		RightHand->SetHand(EControllerHand::Right);
	}

	LeftHand = GetWorld()->SpawnActor<AESCCharacterHand>(ESCHandClass);
	if (LeftHand != nullptr)
	{
		LeftHand->AttachToComponent(ESCCharacterRoot, FAttachmentTransformRules::KeepRelativeTransform);
		LeftHand->SetOwner(this);
		LeftHand->SetHand(EControllerHand::Left);
	}
	
}

// Called every frame
void AESC_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector NewCameraOffset = Camera->GetComponentLocation() - GetActorLocation();
	NewCameraOffset.Z = 0;
	AddActorWorldOffset(NewCameraOffset);
	ESCCharacterRoot->AddWorldOffset(-NewCameraOffset);
	
}

// Called to bind functionality to input
void AESC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AESC_Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AESC_Character::MoveRight);

}

void AESC_Character::MoveForward(float value)
{
	AddMovementInput(Camera->GetForwardVector(), value);
}

void AESC_Character::MoveRight(float value)
{
	AddMovementInput(Camera->GetRightVector(), value);
}

