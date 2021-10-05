// Fill out your copyright notice in the Description page of Project Settings.


#include "CellActor.h"

#include "PurpleBuildActor.h"
#include "RedBuildActor.h"
#include "WhiteBuildActor.h"
#include "YellowBuildActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACellActor::ACellActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CellRootComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CellMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	FScriptDelegate OnClickedDelegate;
	FScriptDelegate OnBeginCursorOverDelegate;
	FScriptDelegate OnEndCursorOverDelegate;
	OnClickedDelegate.BindUFunction(this, "Clicked");
	OnBeginCursorOverDelegate.BindUFunction(this, "BeginCursorOver");
	OnEndCursorOverDelegate.BindUFunction(this, "EndCursorOver");
	OnClicked.Add(OnClickedDelegate);
	OnBeginCursorOver.Add(OnBeginCursorOverDelegate);
	OnEndCursorOver.Add(OnEndCursorOverDelegate);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Materials/Shape_Sphere.Shape_Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}
	Placable = true;
}

// Called when the game starts or when spawned
void ACellActor::BeginPlay()
{
	Super::BeginPlay();

	if (FMath::RandRange(1, 20) > 10)
	{
		StaticMeshComponent->SetMaterial(0, GreenColorOfCell);
		ColorCell = 0;
		EndCursorOverMaterial = GreenColorOfCell;
	}
	else
	{
		StaticMeshComponent->SetMaterial(0, GreyColorOfCell);
		ColorCell = 1;
		EndCursorOverMaterial = GreyColorOfCell;
	}
}

// Called every frame
void ACellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACellActor::Clicked()
{
	if (!Occupied) {
		StaticMeshComponent->SetMaterial(0, BlueColorOfCell);
		Occupied = true;
		Placable = false;
		//BaseBuildClass. = new ARedBuildActor;

		int32 rando = FMath::RandRange(0, 20);

		if (rando < 5)
		{
			if (RedBuildClass)
			{
				auto BuildActor = GetWorld()->SpawnActor<ARedBuildActor>(RedBuildClass, StaticMeshComponent->GetSocketLocation(FName("HouseSocket")), StaticMeshComponent->GetSocketRotation(FName("HouseSocket")));
				BuildActor->OnPickUp();
			}
		}
		else if (rando >= 5 && rando < 10)
		{
			if (YellowBuildClass)
			{
				auto BuildActor = GetWorld()->SpawnActor<AYellowBuildActor>(YellowBuildClass, StaticMeshComponent->GetSocketLocation(FName("HouseSocket")), StaticMeshComponent->GetSocketRotation(FName("HouseSocket")));
				BuildActor->OnPickUp();
			}
		}
		else if (rando >= 10 && rando < 15)
		{
			if (WhiteBuildClass)
			{
				auto BuildActor = GetWorld()->SpawnActor<AWhiteBuildActor>(WhiteBuildClass, StaticMeshComponent->GetSocketLocation(FName("HouseSocket")), StaticMeshComponent->GetSocketRotation(FName("HouseSocket")));
				BuildActor->OnPickUp();
			}
		}
		else
		{
			if (PurpleBuildClass)
			{
				auto BuildActor = GetWorld()->SpawnActor<APurpleBuildActor>(PurpleBuildClass, StaticMeshComponent->GetSocketLocation(FName("HouseSocket")), StaticMeshComponent->GetSocketRotation(FName("HouseSocket")));
				BuildActor->OnPickUp();
			}
		}
	}
}

void ACellActor::BeginCursorOver()
{
	if(Placable)
	StaticMeshComponent->SetMaterial(0, BeginCursorOverMaterial);
}

void ACellActor::EndCursorOver()
{

	if (!Occupied) {
		StaticMeshComponent->SetMaterial(0, EndCursorOverMaterial);
	}
	else {
		StaticMeshComponent->SetMaterial(0, BlueColorOfCell);
	}

}

/*void ACellActor::Update()
{
	/*if (AliveNext) {
		StaticMeshComponent->SetMaterial(0, ClickedMaterial);
		Alive = true;
		SetActorHiddenInGame(false);
	}
	else {
		SetActorHiddenInGame(true);
		StaticMeshComponent->SetMaterial(0, EndCursorOverMaterial);
		Alive = false;
	}
}*/

int32 ACellActor::GetColorCell()
{
	return ColorCell;
}