// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BulletEmitterComponent.generated.h"

UCLASS()
class UEDANMAKUPROJECT_API ABulletEmitterComponent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABulletEmitterComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FTimerHandle FireTimerHandle;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	TSubclassOf<class ABullet> BulletClass;

	// 弾を発射する感覚（秒）
	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	float ShotRate;
	// 現在の発射角度
	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	FRotator ShotRotation;
	// 発射間隔ごとに回転させる角度
	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	FRotator ShotRotationRate;

	// 同時に発射する弾数
	UPROPERTY(EditAnywhere, Category = "BulletEmitter", meta = (ClampMin = 0))
	uint32 ShotCount;

	UFUNCTION(BlueprintCallable, Category = "BulletEmitter")
	void Fire();
};
