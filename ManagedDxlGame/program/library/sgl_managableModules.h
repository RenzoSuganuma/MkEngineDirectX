#pragma once

// sgl���C�u�����ŊǗ��ł��郂�W���[�����ׂĂ��p�����ׂ��C���^�t�F�[�X
class IManagableModule {
	/* --- ���[�U�[��`���W���[����override����֐� --- */
protected:
	// ���W���[���̏�����
	virtual void Initialize() = 0;
	// ���W���[���̍X�V
	virtual void Update(float delta_time) = 0;
	// ���W���[���̕`��
	virtual void Draw() = 0;
	// ���W���[���̓��ł̉��
	virtual void Release() = 0;
	// ���W���[���̔j��
	virtual void Finalize() = 0;
};