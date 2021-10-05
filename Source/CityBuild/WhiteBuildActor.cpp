// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteBuildActor.h"

#include "CityBuildGameModeBase.h"

AWhiteBuildActor::AWhiteBuildActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Materials/WhiteHouse.WhiteHouse"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	/*ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 6;
	GameMode->TotalPoints += BuildPoints;*/
}

void AWhiteBuildActor::OnPickUp(float bonus)
{
	ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 6* bonus;
	GameMode->TotalPoints += BuildPoints;
}