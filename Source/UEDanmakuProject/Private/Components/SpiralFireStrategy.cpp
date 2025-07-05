#include "Components/SpiralFireStrategy.h"

#include "Projectiles/Bullet.h"

USpiralFireStrategy::USpiralFireStrategy()
{
	CurrentPatternRotation = FRotator::ZeroRotator;
}


void USpiralFireStrategy::Fire()
{
	if (!DanmakuPatternAsset || !GetOwner())
	{
		return;
	}

	const FDanmakuPatternData& DanmakuPatternData = DanmakuPatternAsset->PatternData;
	AActor* Emitter = GetOwner();
	const uint32 NumberOfShots = DanmakuPatternData.NumberOfShots;

	if (DanmakuPatternData.BulletClass && NumberOfShots > 0)
	{
		// 敵の現在の向き
		const FRotator EmitterRotation = Emitter->GetActorRotation();

		// N-way弾間の角度
		// (例: 4方向なら360 / 4 = 90 度ずつずらす)
		const float ShotAngleBetweenShots = 360.0f / NumberOfShots;

		for (uint32 i = 0; i < NumberOfShots; i++)
		{
			// パターン全体の3D回転 + N-way の弾の広がり
			const FRotator NextShotRotation = CurrentPatternRotation + FRotator(0.0f, i * ShotAngleBetweenShots, 0.0f);

			// 弾の発射角度
			const FRotator BulletRotation = EmitterRotation + NextShotRotation;
			const FVector SpawnLocation = Emitter->GetActorLocation();

			GetWorld()->SpawnActor<ABullet>(DanmakuPatternData.BulletClass, SpawnLocation, BulletRotation);
		}

		// 次の弾の発射角度
		CurrentPatternRotation += DanmakuPatternData.RotationPerShot;
		CurrentPatternRotation.Normalize();
	}
}

float USpiralFireStrategy::GetShotRate() const
{
	if (DanmakuPatternAsset)
	{
		return DanmakuPatternAsset->PatternData.ShotRate;
	}
	return 1.0f;
}
