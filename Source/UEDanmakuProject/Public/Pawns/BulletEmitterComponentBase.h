// Copyright (c) 2025, Hiroya-W All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BulletEmitterComponentBase.generated.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Danmaku")
	UStaticMeshComponent* MeshComponent;};
