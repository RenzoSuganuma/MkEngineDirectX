#include "../library/sgl.h"
#include "DxLib.h"

#pragma once
class TestActor : public Actor
{
	// モジュールの初期化
	void Initialize() override {

	}
	// モジュールの更新
	void Update(float delta_time) override {
		base::Update(delta_time);

		DxLib::DrawString(0, 0, "go", -1);
	}
	// モジュールの描画
	void DrawGraphics() override {

	}
	// モジュールの内での解放
	void MemRelease() override {

	}
	// モジュールの破棄
	void Finalize() override {

	}
};

