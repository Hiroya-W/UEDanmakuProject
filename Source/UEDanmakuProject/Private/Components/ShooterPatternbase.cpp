// Copyright (c) 2025, Hiroya-W All rights reserved.

#include "Components/ShooterPattenBase.h"

void UShooterPattenBase::BeginPlay()
{
	Super::BeginPlay();

	// Timerをセットする
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &UShooterPattenBase::Fire, this->GetShotRate(), true,
										   this->GetShotRate());
}

void UShooterPattenBase::TickComponent(float DeltaTime, ELevelTick TickType,
									   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
