// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuildActor.h"

// Sets default values
ABaseBuildActor::ABaseBuildActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CellRootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildMesh"));
	MeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseBuildActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseBuildActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/* Attach weapon to Socket in CharacterOwner Mesh */
void ABaseBuildActor::AttachToCell()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));
	UE_LOG(LogTemp, Warning, TEXT("Character name: %s"), *(BuildingHolder->GetName()));

	UStaticMeshComponent* Cell = BuildingHolder->GetStaticMesh();
	MeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	MeshComponent->SetHiddenInGame(false);
	MeshComponent->AttachTo(Cell, "HouseSocket");

}