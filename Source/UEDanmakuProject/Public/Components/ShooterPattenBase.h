// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "ShooterPattenBase.generated.h"

class AStraightBullet;

UCLASS(Abstract)
class UEDANMAKUPROJECT_API UShooterPattenBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// TODO: 真っすぐ進むだけの弾じゃないクラスを定義して置き換える
	UPROPERTY(EditAnywhere, Category = "Danmaku")
	TSubclassOf<class AStraightBullet> BulletClass;

	FTimerHandle FireTimerHandle;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	// 弾幕パターンのロジックをここに書く
	virtual void Fire() PURE_VIRTUAL(UShooterPattenBase::Fire);

	// タイマーセットのために発射間隔を取得する関数を定義しておく
	virtual float GetShotRate() const PURE_VIRTUAL(UShooterPattenBase::GetShotRate, return 1.0f;);
};
