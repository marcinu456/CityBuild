// Fill out your copyright notice in the Description page of Project Settings.


#include "YellowBuildActor.h"

#include "CityBuildGameModeBase.h"

AYellowBuildActor::AYellowBuildActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Materials/YellowHouse.YellowHouse"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	/*ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 8;
	GameMode->TotalPoints += BuildPoints;*/
}

void AYellowBuildActor::OnPickUp(float bonus)
{
	ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 6 * bonus;
	GameMode->TotalPoints += BuildPoints;
}