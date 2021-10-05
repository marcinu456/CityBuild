// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuildActor.h"
#include "PurpleBuildActor.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILD_API APurpleBuildActor : public ABaseBuildActor
{
	GENERATED_BODY()
public:
	APurpleBuildActor();
	virtual void OnPickUp(int32 bonus = 1) override;
};
