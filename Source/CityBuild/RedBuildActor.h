// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuildActor.h"
#include "RedBuildActor.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILD_API ARedBuildActor : public ABaseBuildActor
{
	GENERATED_BODY()

		
public:
	ARedBuildActor();
	virtual void OnPickUp(float bonus = 1) override;
};
