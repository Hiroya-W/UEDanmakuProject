// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "Projectiles/Bullet.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(
		TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereVisualAsset.Object);
		MeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MeshComponent->SetWorldScale3D(FVector(0.5f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterialAsset(
		TEXT("/Game/Projectiles/Bullet/M_Bullet_Big.M_Bullet_Big"));

	if (SphereMaterialAsset.Succeeded())
	{
		MeshComponent->SetMaterial(0, SphereMaterialAsset.Object);
	}

	ProjectileMovementComponent =
		CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(RootComponent);
	ProjectileMovementComponent->InitialSpeed = 300.0f;
	ProjectileMovementComponent->MaxSpeed = 300.0f;
	// 速度の方向に合わせて回転しない
	ProjectileMovementComponent->bRotationFollowsVelocity = false;
	// 跳ね返りはしない
	ProjectileMovementComponent->bShouldBounce = false;
	// 重力の影響を受けないように
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	InitialLifeSpan = 10.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
