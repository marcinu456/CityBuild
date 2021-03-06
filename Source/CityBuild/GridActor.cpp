// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"

// Sets default values
AGridActor::AGridActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FScriptDelegate OnClickedDelegate;
	OnClickedDelegate.BindUFunction(this, "Clicked");
	OnClicked.Add(OnClickedDelegate);
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
	const float EffectiveBoxExtentX = BoxExtent.X * Scale.X + Offset;
	const float YStep = EffectiveBoxExtentY * 2;
	const float XStep = EffectiveBoxExtentX * 2;
	const float BoardWidth = EffectiveBoxExtentY * 2 * Width;
	const float BoardHeight = EffectiveBoxExtentX * 2 * Height;

	const FVector Origin = GetActorLocation();
	const FVector TopLeft(Origin.X + BoardHeight / 2 - EffectiveBoxExtentX, Origin.Y - BoardWidth / 2 + EffectiveBoxExtentY, Origin.Z );

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			const FVector Loc(TopLeft.X - i * XStep, TopLeft.Y + j * YStep, Origin.Z );
			ACellActor* const SpawnedActorRef = GetWorld()->SpawnActor<ACellActor>(CellActor, Loc, GetActorRotation());
			SpawnedActorRef->SetCellPlace(i, j);
			CellActors.Add(SpawnedActorRef);
		}
	}


}

// Called every frame
void AGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(first)
	{
		Clicked();
	}
	else
	{
		WaitForFirst();
	}
}

void AGridActor::WaitForFirst()
{
	for (auto& Cell : CellActors)
	{
		if (Cell->GetOccupied())
		{
			for (auto& Cello : CellActors)
			{
				Cello->SetPlacable(false);
			}
			first = true;
			int32 i;
			int32 j;
			Cell->GetCellPlace(i, j);
			SetAliveNeighbors(i, j);
			break;
		}
	}
}

void AGridActor::Clicked()
{

	for(auto& Cell:CellActors)
	{
		if(Cell->GetOccupied())
		{
			int32 i;
			int32 j;
			Cell->GetCellPlace(i, j);
			SetAliveNeighbors(i, j);
		}
	}
}

int AGridActor::CountAliveNeighbors(const int32 i, const int32 j) {
	int NumAliveNeighbors = 0;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (!(l == 0 && k == 0)) {
				const int effective_i = i + k;
				const int effective_j = j + l;
				if ((effective_i >= 0 && effective_i < Height) && (effective_j >= 0 && effective_j < Width)) {
					if (CellActors[effective_j + effective_i * Width]->GetPlacable()) {
						NumAliveNeighbors++;
					}
				}
			}
		}
	}
	return NumAliveNeighbors;
}

void AGridActor::SetAliveNeighbors(const int32 i, const int32 j)
{
	for (int32 k = -1; k <= 1; k++) {
		for (int32 l = -1; l <= 1; l++) {
			if (!(l == 0 && k == 0)) {
				const int32 effective_i = i + k;
				const int32 effective_j = j + l;
				if ((effective_i >= 0 && effective_i < Height) && (effective_j >= 0 && effective_j < Width)) {
					CellActors[effective_j + effective_i * Width]->SetPlacable(true);

				}
			}
		}
	}
}