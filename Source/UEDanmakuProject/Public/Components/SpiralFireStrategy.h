// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "Components/FireStrategyBase.h"
#include "CoreMinimal.h"
#include "Data/DanmakuPatternAsset.h"

#include "SpiralFireStrategy.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UEDANMAKUPROJECT_API USpiralFireStrategy : public UFireStrategyBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Danmaku")
	UDanmakuPatternAsset* DanmakuPatternAsset;

private:
	FRotator CurrentPatternRotation;

public:
	virtual void Fire() override;
	virtual float GetShotRate() override;
};
