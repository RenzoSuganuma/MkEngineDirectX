

#pragma once
namespace MkEngine
{
	enum MkBehaviourType
	{
		/// <summary> �ʏ�̃��C�t�T�C�N�� </summary>
		Normal,
		/// <summary> �O���t�B�b�N�X�̃��C�t�T�C�N���i�`�揈�����ǉ��j </summary>
		Graphics,
		/// <summary> �������Z�̃��C�t�T�C�N���i���t���[���Ăяo���ɐ����j </summary>
		Physics,
		/// <summary> �v�f�� </summary>
		Length
	};

	class MkBehaviour
	{
	private:
		MkEngine::MkBehaviourType m_type;

	public:
		const MkEngine::MkBehaviourType& get_BehaviourType()
		{
			return m_type;
		}

		virtual void Initialize() {}

		virtual void FixedUpdate(float deltaTime) {}

		virtual void DrawGraphics() {}

		virtual void MemRelease() {}
	};
}
