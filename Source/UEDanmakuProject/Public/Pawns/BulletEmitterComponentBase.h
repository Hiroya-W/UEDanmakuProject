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
	void Fire() const;
	FTimerHandle FireTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Danmaku")
	UStaticMeshComponent* MeshComponent;

	// 弾幕のパターン
	// これを差し替えれば様々な弾幕を撃つものに差し替えられる
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Danmaku", meta = (MustImplement = "FireStrategyBase"))
	UFireStrategyBase* FireStrategy;
};
