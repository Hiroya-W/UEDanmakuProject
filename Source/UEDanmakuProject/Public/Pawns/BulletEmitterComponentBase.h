// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BulletEmitterComponentBase.generated.h"


class UFireStrategyBase;
UCLASS()
class UEDANMAKUPROJECT_API ABulletEmitterComponentBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABulletEmitterComponentBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// 弾幕のパターン
	// これを差し替えれば様々な弾幕を撃つものに差し替えられる
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Danmaku", meta = (AllowPrivateAccess = "true"))
	UFireStrategyBase* FireStrategy;

	void Fire() const;
	FTimerHandle FireTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
