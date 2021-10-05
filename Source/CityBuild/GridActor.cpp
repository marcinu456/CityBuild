// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"

// Sets default values
AGridActor::AGridActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<UStaticMeshComponent*> Components;
	CellActor.GetDefaultObject()->GetComponents<UStaticMeshComponent>(Components);
	const FVector BoxExtent = Components[0]->GetStaticMesh()->GetBounds().BoxExtent;
	const FVector Scale = Components[0]->GetRelativeTransform().GetScale3D();

	ensure(Components.Num() > 0);

	const float EffectiveBoxExtentY = BoxExtent.Y * Scale.Y + Offset;
	const float EffectiveBoxExtentZ = BoxExtent.Z * Scale.Z + Offset;
	const float YStep = EffectiveBoxExtentY * 2;
	const float ZStep = EffectiveBoxExtentZ * 2;
	const float BoardWidth = EffectiveBoxExtentY * 2 * Width;
	const float BoardHeight = EffectiveBoxExtentZ * 2 * Height;

	const FVector Origin = GetActorLocation();
	const FVector TopLeft(Origin.X, Origin.Y - BoardWidth / 2 + EffectiveBoxExtentY, Origin.Z + BoardHeight / 2 - EffectiveBoxExtentZ);

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			const FVector Loc(Origin.X, TopLeft.Y + j * YStep, TopLeft.Z - i * ZStep);
			ACellActor* const SpawnedActorRef = GetWorld()->SpawnActor<ACellActor>(CellActor, Loc, GetActorRotation()); //const pointer to non-const CellActor
			CellActors.Add(SpawnedActorRef);
		}
	}


}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

