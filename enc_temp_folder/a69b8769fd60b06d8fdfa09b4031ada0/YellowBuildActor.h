// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuildActor.h"
#include "YellowBuildActor.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILD_API AYellowBuildActor : public ABaseBuildActor
{
	GENERATED_BODY()
public:
	AYellowBuildActor();
	virtual void OnPickUp(int32 bonus = 1) override;
};
