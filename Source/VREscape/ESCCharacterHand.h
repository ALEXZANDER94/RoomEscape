// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ESCCharacterHand.generated.h"

UCLASS()
class VRESCAPE_API AESCCharacterHand : public AActor
{
	GENERATED_BODY()
	
private:

	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedAction, AActor* OtherActor);

	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedAction, AActor* OtherActor);
public:	
	// Sets default values for this actor's properties
	AESCCharacterHand();

	void SetHand(EControllerHand Hand);
	bool CheckSearch() const;
	void Search();
	void PairController(AESCCharacterHand* Hand);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* MotionController;

	UPROPERTY(EditAnywhere)
	class UHapticFeedbackEffect_Base* RumbleEffect;

	//States
	bool bCanSearch = false;
	bool bIsSearching = false;

	AESCCharacterHand* OtherController;
};
