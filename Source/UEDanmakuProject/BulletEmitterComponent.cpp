// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "BulletEmitterComponent.h"

// Sets default values
ABulletEmitterComponent::ABulletEmitterComponent()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABulletEmitterComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletEmitterComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABulletEmitterComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

