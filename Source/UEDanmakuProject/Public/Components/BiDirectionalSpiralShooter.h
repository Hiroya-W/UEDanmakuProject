// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "Components/ShooterPattenBase.h"
#include "CoreMinimal.h"

#include "BiDirectionalSpiralShooter.generated.h"

/**
 * 両回転渦巻弾
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UEDANMAKUPROJECT_API UBiDirectionalSpiralShooter : public UShooterPattenBase
{
	GENERATED_BODY()
public:
	UBiDirectionalSpiralShooter();

	virtual void Fire() override;
	virtual float GetShotRate() const override;

	// 弾を発射する感覚（秒）
	UPROPERTY(EditAnywhere, Category = "Danmaku")
	float ShotRate;
	// 現在の発射角度
	UPROPERTY(EditAnywhere, Category = "Danmaku")
	TArray<FRotator> CurrentPatternRotations;
	// 発射間隔ごとに回転させる角度
	UPROPERTY(EditAnywhere, Category = "Danmaku")
	TArray<FRotator> RotationPerShots;
	// 同時に発射する弾数
	UPROPERTY(EditAnywhere, Category = "Danmaku", meta = (ClampMin = 0))
	uint32 NumberOfShots;
};
