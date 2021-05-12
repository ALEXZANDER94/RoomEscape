// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ESCCharacterHand.h"
#include "ESC_Character.generated.h"

UCLASS()
class VRESCAPE_API AESC_Character : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class UCameraComponent* Camera;

	UPROPERTY()
	class USceneComponent* ESCCharacterRoot;

	UPROPERTY()
	AESCCharacterHand* RightHand;

	UPROPERTY()
	AESCCharacterHand* LeftHand;

	void MoveForward(float value);
	void MoveRight(float value);


public:
	// Sets default values for this character's properties
	AESC_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AESCCharacterHand> ESCHandClass;
};
