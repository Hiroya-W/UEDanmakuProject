// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "Pawns/BulletEmitterComponentBase.h"

#include "Components/NoFireStrategy.h"

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

	// デフォルト値として弾幕を撃たない設定を利用する
	FireStrategy = CreateDefaultSubobject<UNoFireStrategy>(TEXT("FireStrategy"));
}

// Called when the game starts or when spawned
void ABulletEmitterComponentBase::BeginPlay()
{
	Super::BeginPlay();

	if (FireStrategy)
	{
		// 発射間隔をコンポーネントから取得してタイマーを設定する
		GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ABulletEmitterComponentBase::Fire,
											   FireStrategy->GetShotRate(), true, FireStrategy->GetShotRate());
	}
}

// Called every frame
void ABulletEmitterComponentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABulletEmitterComponentBase::Fire() const
{
	// 弾の発射ロジックは与えられたFireStrategyに従う
	if (FireStrategy)
	{
		FireStrategy->Fire();
	}
}
