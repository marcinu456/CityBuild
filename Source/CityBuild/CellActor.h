// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellActor.generated.h"

UCLASS()
class CITYBUILD_API ACellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACellActor();

	void SetOccupied(const bool IsOccupied) {
		this->Occupied = IsOccupied;
	}

	void SetPlacable(const bool IsPlacable) {
		this->Placable = IsPlacable;
	}

	bool GetPlacable() {
		return this->Placable;
	}

	bool GetOccupied() {
		return this->Occupied;
	}

	void GetCellPlace(int32& x, int32& y) {
		x = CellX;
		y = CellY;
	}

	void SetCellPlace(int32 x, int32 y) {
		CellX = x;
		CellY = y;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 GetColorCell();

	FORCEINLINE class UStaticMeshComponent* GetStaticMesh() const { return StaticMeshComponent; }
private:
	UFUNCTION()
		void Clicked();
	UFUNCTION()
		void BeginCursorOver();
	UFUNCTION()
		void EndCursorOver();


	mutable bool Occupied;
	mutable bool Placable;

	int32 CellX;
	int32 CellY;


	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* StaticMeshComponent;

	/** Material for when the cell is alive. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* ClickedMaterial;
	/** Material for when player hovers over the cell in edit mode. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* BeginCursorOverMaterial;
	/** Material for when the cell is not alive in edit mode. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* EndCursorOverMaterial;
	/** Material for when the cell is not alive in edit mode. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* GreenColorOfCell;
	/** Material for when the cell is not alive in edit mode. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* GreyColorOfCell;
	/** Material for when the cell is not alive in edit mode. */
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", Category = "Materials"))
		UMaterialInterface* BlueColorOfCell;

	int32 ColorCell;


	UPROPERTY(EditDefaultsOnly, Category = Build)
		TSubclassOf<class ABaseBuildActor> RedBuildClass;
	UPROPERTY(EditDefaultsOnly, Category = Build)
		TSubclassOf<class ABaseBuildActor> YellowBuildClass;
	UPROPERTY(EditDefaultsOnly, Category = Build)
		TSubclassOf<class ABaseBuildActor> PurpleBuildClass;
	UPROPERTY(EditDefaultsOnly, Category = Build)
		TSubclassOf<class ABaseBuildActor> WhiteBuildClass;


};
