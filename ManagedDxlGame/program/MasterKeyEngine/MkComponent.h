#pragma once

#include "../library/sgl_actor.h"
#include "../library/sgl_component.h"

namespace MkEngine
{
	/// <summary> MkEngine::Component ���b�p�[ </summary>
	struct MkComponent : public Component
	{
	public:

		/// <summary> �A�N�^�[�̃|�C���^��Ԃ� </summary>
		const Actor* const GetActor() const
		{
			return m_attachedActor.get();
		}
	};
}
