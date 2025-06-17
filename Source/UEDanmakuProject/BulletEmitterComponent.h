// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BulletEmitterComponent.generated.h"

UCLASS()
class UEDANMAKUPROJECT_API ABulletEmitterComponent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABulletEmitterComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FTimerHandle FireTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	TSubclassOf<class AStraightBullet> BulletClass;

	// 弾を発射する感覚（秒）
	UPROPERTY(EditAnywhere, Category = "BulletEmitter")
	float ShotRate;

	UFUNCTION(BlueprintCallable, Category = "BulletEmitter")
	void Fire();
};
