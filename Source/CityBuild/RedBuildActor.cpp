// Fill out your copyright notice in the Description page of Project Settings.


#include "RedBuildActor.h"

#include "CityBuildGameModeBase.h"

ARedBuildActor::ARedBuildActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Materials/RedHouse.RedHouse"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	/*ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 10;
	GameMode->TotalPoints += BuildPoints;*/
}

void ARedBuildActor::OnPickUp(float bonus)
{
	ACityBuildGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACityBuildGameModeBase>();
	BuildPoints = 10 * bonus;
	GameMode->TotalPoints += BuildPoints;
}