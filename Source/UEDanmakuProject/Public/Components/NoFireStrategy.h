// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "Components/FireStrategyBase.h"
#include "CoreMinimal.h"

#include "NoFireStrategy.generated.h"

/**
 * 何も弾を撃たない
 */
UCLASS()
class UEDANMAKUPROJECT_API UNoFireStrategy : public UFireStrategyBase
{
	GENERATED_BODY()

public:
	UNoFireStrategy();

	virtual void Fire() override;
	virtual float GetShotRate() const override;
};
