#pragma once

#include "memory"
#include "MkComponent.h"
#include "dxe_sgl_header.h"

namespace MkEngine
{
	struct MkActor : public Actor
	{
	public:
		MkActor() {}
		~MkActor() {}

		/// <summary> コンポーネントの追加 </summary>
		template< typename T >
		MkEngine::MkComponent* const AddComponent()
		{
			auto c = std::make_shared<T>();
			m_components.emplace_back(c);
			return  dynamic_cast<MkEngine::MkComponent*>(c.get());
		}
	};
}