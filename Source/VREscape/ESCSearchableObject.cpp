// Fill out your copyright notice in the Description page of Project Settings.


#include "ESCSearchableObject.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Math/BoxSphereBounds.h"

// Sets default values
AESCSearchableObject::AESCSearchableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	SetRootComponent(BoxCollider);

	ObjectShape = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectShape->SetupAttachment(BoxCollider);
}

// Called when the game starts or when spawned
void AESCSearchableObject::BeginPlay()
{
	Super::BeginPlay();
	
	FBoxSphereBounds MeshBounds = Cast<USceneComponent>(ObjectShape)->Bounds;
	
	BoxCollider->SetBoxExtent(MeshBounds.BoxExtent);
	
}

// Called every frame
void AESCSearchableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

