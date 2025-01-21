#pragma once

#include "../library/sgl_actor.h"
#include "../library/sgl_component.h"

namespace MkEngine
{
	/// <summary> MkEngine::Component ラッパー </summary>
	struct MkComponent : public Component
	{
	public:

		/// <summary> アクターのポインタを返す </summary>
		const Actor* const GetActor() const
		{
			return m_attachedActor.get();
		}
	};
}
