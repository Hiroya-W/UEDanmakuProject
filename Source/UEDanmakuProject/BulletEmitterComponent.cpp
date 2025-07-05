// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "BulletEmitterComponent.h"

#include "Bullet.h"

// Sets default values
ABulletEmitterComponent::ABulletEmitterComponent()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(
		TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeVisualAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(CubeVisualAsset.Object);
		MeshComponent->SetWorldScale3D(FVector(0.5f));
	}

	ShotRate = 1.0f;
	ShotRotation = FRotator::ZeroRotator;
	ShotRotationRate = FRotator(0.0f, 1.0f, 0.0f);
	ShotCount = 4;
}

// Called when the game starts or when spawned
void ABulletEmitterComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ABulletEmitterComponent::Fire, ShotRate, true,
										   ShotRate);
}

// Called every frame
void ABulletEmitterComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABulletEmitterComponent::Fire()
{
	if (BulletClass && ShotCount > 0)
	{
		// 敵の現在の向き
		const FRotator EmitterRotation = GetActorRotation();

		// N-way弾間の角度
		// (例: 4方向なら360 / 4 = 90 度ずつずらす)
		const float ShotAngleBetweenShots = 360.0f / ShotCount;

		for (uint32 i = 0; i < ShotCount; i++)
		{
			// パターン全体の3D回転 + N-way の弾の広がり
			const FRotator NextShotAngle = ShotRotation + FRotator(0.0f, i * ShotAngleBetweenShots, 0.0f);

			// 弾の発射角度
			const FRotator BulletRotation = EmitterRotation + NextShotAngle;
			const FVector SpawnLocation = GetActorLocation();

			GetWorld()->SpawnActor<ABullet>(BulletClass, SpawnLocation, BulletRotation);
		}

		// 次の弾の発射角度
		ShotRotation += ShotRotationRate;
		ShotRotation.Normalize();
	}
}
