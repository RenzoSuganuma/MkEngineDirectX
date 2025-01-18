#include "sgl_object.h"

#pragma once

/// <summary> タスクシステムに組み込めるもの </summary>
class IModule : public Object
{
public:
	// モジュールの初期化
	virtual void Initialize() = 0;
	// モジュールの更新
	virtual void Update(float delta_time) = 0;
	// モジュールの描画
	virtual void Draw() = 0;
	// モジュールの内での解放
	virtual void MemRelease() = 0;
	// モジュールの破棄
	virtual void Finalize() = 0;
};