// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CellActor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BaseBuildActor.generated.h"

UCLASS(Abstract)
class CITYBUILD_API ABaseBuildActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseBuildActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AttachToCell();
private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshComponent;

	ACellActor* BuildingHolder;

};
