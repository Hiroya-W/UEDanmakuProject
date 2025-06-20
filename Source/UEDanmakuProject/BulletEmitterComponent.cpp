// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "BulletEmitterComponent.h"

#include "StraightBullet.h"

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
	ShotAngle = 0.0f;
	ShotAngleRate = 1.0f;
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
	if (BulletClass)
	{
		// 敵の現在の向き
		const FRotator EmitterRotation = GetActorRotation();
		// 弾の発射角度
		const FRotator BulletRotation = EmitterRotation + FRotator(0, ShotAngle, 0);
		const FVector SpawnLocation = GetActorLocation();

		GetWorld()->SpawnActor<AStraightBullet>(BulletClass, SpawnLocation, BulletRotation);

		// 次の弾の発射角度
		ShotAngle = FMath::Fmod(ShotAngle + ShotAngleRate, 360.0f);
	}
}
