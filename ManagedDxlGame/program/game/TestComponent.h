#include "../library/sgl.h"
#include "DxLib.h"

#pragma once
class TestComponent : public Component
{
	// ���W���[���̏�����
	void Initialize() override {

	}
	// ���W���[���̍X�V
	void Update(float delta_time) override {
		base::Update(delta_time);

		DxLib::DrawString(0, 10, "test_", -1);
	}
	// ���W���[���̕`��
	void DrawGraphics() override {

	}
	// ���W���[���̓��ł̉��
	void MemRelease() override {

	}
	// ���W���[���̔j��
	void Finalize() override {

	}
};

