#pragma once

UCLASS(Abstract)
class UEDanmakuProject_API UFireStrategyBase : public UActorComponent
{
public:
	GENERATED_BODY()
	// 発射ロジック
	virtual void Fire() PURE_VIRTUAL(UFireStrategyBase::Fire);

	// 発射間隔を返す
	// 現状このクラスのインスタンスを持つActorでタイマーを設定しているので取得できるようにしている
	virtual float GetShotRate() PURE_VIRTUAL(UFireStrategyBase::GetShotRate, return 0.0f;);
};
