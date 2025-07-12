// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "Components/BiDirectionalSpiralShooter.h"

UBiDirectionalSpiralShooter::UBiDirectionalSpiralShooter()
{
	CurrentPatternRotations = {FRotator::ZeroRotator, FRotator::ZeroRotator};
	ShotRate = 0.15f;
	RotationPerShots = {FRotator(0.0f, 0.0f, 10.0f), FRotator(0.0f, 0.0f, -5.0f)};
	NumberOfShots = 4;
}

void UBiDirectionalSpiralShooter::Fire()
{
	if (!GetOwner())
	{
		return;
	}

	AActor* Emitter = GetOwner();

	if (BulletClass && NumberOfShots > 0)
	{
		// 敵の現在の向き
		const FRotator EmitterRotation = Emitter->GetActorRotation();

		// N-way弾間の角度
		// (例: 4方向なら360 / 4 = 90 度ずつずらす)
		const float ShotAngleBetweenShots = 360.0f / NumberOfShots;

		// 両方向に
		for (uint32 j = 0; j < 2; j++)
		{
			const FRotator CurrentPatternRotation = CurrentPatternRotations[j];
			const FRotator RotationPerShot = RotationPerShots[j];

			for (uint32 i = 0; i < NumberOfShots; i++)
			{
				// パターン全体の3D回転 + N-way の弾の広がり
				const FRotator NextShotRotation =
					CurrentPatternRotation + FRotator(0.0f, i * ShotAngleBetweenShots, 0.0f);

				// 弾の発射角度
				const FRotator BulletRotation = EmitterRotation + NextShotRotation;
				const FVector SpawnLocation = Emitter->GetActorLocation();

				GetWorld()->SpawnActor<ABullet>(BulletClass, SpawnLocation, BulletRotation);
			}
			// 次の弾の発射角度
			CurrentPatternRotations[j] = CurrentPatternRotation + RotationPerShot;
			CurrentPatternRotations[j].Normalize();
		}
	}
}

float UBiDirectionalSpiralShooter::GetShotRate() const
{
	return ShotRate;
}
