// Copyright (c) 2025, Hiroya-W All rights reserved.


#include "Components/NoFireStrategy.h"

void UNoFireStrategy::Fire()
{
}
float UNoFireStrategy::GetShotRate() const
{
	// 何もしないがタイマーの設定には値が必要なので
	return 0.0f;
}
