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

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshComponent;

	int32 BuildPoints = 0;

public:
	virtual void OnPickUp(int32 bonus=1) PURE_VIRTUAL(ABaseBuildActor::OnPickUp, );

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AttachToCell();
private:


	ACellActor* BuildingHolder;

};
