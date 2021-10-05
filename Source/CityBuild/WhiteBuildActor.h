// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuildActor.h"
#include "WhiteBuildActor.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILD_API AWhiteBuildActor : public ABaseBuildActor
{
	GENERATED_BODY()
public:
	AWhiteBuildActor();

	virtual void OnPickUp(float bonus = 1) override;
};
