// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "DanmakuPatternAsset.generated.h"

class ABullet;

// 弾幕に必要なパラメータをまとめている構造体
USTRUCT(BlueprintType)
struct FDanmakuPatternData
{
	GENERATED_BODY()

	// 発射する弾のクラス
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABullet> Bullet;

	// 弾を発射する間隔（秒）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0))
	float ShotRate = 1.0f;

	// 同時に発射する弾数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0))
	int32 NumberOfShots = 1;

	// 発射間隔ごとに回転させる角度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotationPerShot = FRotator::ZeroRotator;
};

UCLASS()
class UEDANMAKUPROJECT_API UDanmakuPatternAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Danmaku")
	FDanmakuPatternData PatternData;
};
