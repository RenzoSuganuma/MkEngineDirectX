#include "sgl_object.h"

#pragma once

/// <summary> �^�X�N�V�X�e���ɑg�ݍ��߂���� </summary>
class IModule : public Object
{
public:
	// ���W���[���̏�����
	virtual void Initialize() = 0;
	// ���W���[���̍X�V
	virtual void Update(float delta_time) = 0;
	// ���W���[���̕`��
	virtual void Draw() = 0;
	// ���W���[���̓��ł̉��
	virtual void MemRelease() = 0;
	// ���W���[���̔j��
	virtual void Finalize() = 0;
};