// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "Pawns/BulletEmitterComponentBase.h"

// Sets default values
ABulletEmitterComponentBase::ABulletEmitterComponentBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 自分の見た目を立方体として表現しておく
	// TODO:  いい感じになおす
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(
		TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeVisualAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(CubeVisualAsset.Object);
		MeshComponent->SetWorldScale3D(FVector(0.5f));
	}
}

// Called when the game starts or when spawned
void ABulletEmitterComponentBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletEmitterComponentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABulletEmitterComponentBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

