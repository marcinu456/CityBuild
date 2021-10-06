// Fill out your copyright notice in the Description page of Project Settings.


#include "PurpleBuildActor.h"

#include "CityBuildGameModeBase.h"

APurpleBuildActor::APurpleBuildActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Materials/PurpleHouse.PurpleHouse"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	/*ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 5;
	GameMode->TotalPoints += BuildPoints;*/
}

void APurpleBuildActor::OnPickUp(float bonus)
{
	ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 5 * bonus;
	GameMode->TotalPoints += BuildPoints;
}