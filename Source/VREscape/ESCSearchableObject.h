// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ESCSearchableObject.generated.h"

UCLASS()
class VRESCAPE_API AESCSearchableObject : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* ObjectShape;

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;
public:	
	// Sets default values for this actor's properties
	AESCSearchableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
