#pragma once

#include "FireStrategyBase.generated.h"

UCLASS(Abstract)
class UEDANMAKUPROJECT_API UFireStrategyBase : public UActorComponent
{
	GENERATED_BODY()
public:
	UFireStrategyBase();
	
	// 発射ロジック
	virtual void Fire() PURE_VIRTUAL(UFireStrategyBase::Fire);

	// 発射間隔を返す
	// 現状このクラスのインスタンスを持つActorでタイマーを設定しているので取得できるようにしている
	virtual float GetShotRate() const PURE_VIRTUAL(UFireStrategyBase::GetShotRate, return 0.0f;);
};
