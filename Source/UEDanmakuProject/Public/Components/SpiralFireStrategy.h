// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "Components/FireStrategyBase.h"
#include "CoreMinimal.h"

#include "SpiralFireStrategy.generated.h"

class UDanmakuFireStrategy;

/**
 * 多方向渦巻弾
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UEDANMAKUPROJECT_API USpiralFireStrategy : public UFireStrategyBase
{
	GENERATED_BODY()

public:
	USpiralFireStrategy();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Danmaku")
	TSoftObjectPtr<class UDanmakuPatternAsset> DanmakuPatternAsset;

private:
	FRotator CurrentPatternRotation;

public:
	virtual void Fire() override;
	virtual float GetShotRate() const override;
};
