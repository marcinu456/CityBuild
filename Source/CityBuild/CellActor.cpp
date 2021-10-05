// Fill out your copyright notice in the Description page of Project Settings.


#include "CellActor.h"

#include "RedBuildActor.h"
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
	StaticMeshComponent->SetMaterial(0, ClickedMaterial);
	Occupied = true;
	//BaseBuildClass. = new ARedBuildActor;
	if(RedBuildClass)
	GetWorld()->SpawnActor<ARedBuildActor>(RedBuildClass, StaticMeshComponent->GetSocketLocation(FName("HouseSocket")), StaticMeshComponent->GetSocketRotation(FName("HouseSocket")));
	StaticMeshComponent->SetMaterial(0, BlueColorOfCell);
}

void ACellActor::BeginCursorOver()
{
	StaticMeshComponent->SetMaterial(0, BeginCursorOverMaterial);
}

void ACellActor::EndCursorOver()
{

	if (!Occupied) {
		StaticMeshComponent->SetMaterial(0, EndCursorOverMaterial);
	}
	else {
		StaticMeshComponent->SetMaterial(0, ClickedMaterial);
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