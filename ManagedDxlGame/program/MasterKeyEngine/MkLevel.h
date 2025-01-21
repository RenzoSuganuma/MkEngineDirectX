#pragma once

#include "../library/sgl_level.h"
#include "MkActor.h"

namespace MkEngine
{
	/// <summary> MkEngine::Level ���b�p�[ </summary>
	class MkLevel : public Level
	{
	private:

		/// <summary> �A�N�^�[�̐��� NOTE:�^���񂠂� </summary>
		template< typename BaseTy, typename DerivedTy >
			requires std::derived_from<DerivedTy, BaseTy>
		const MkEngine::MkActor* InstantiateActorFromClass_Internal()
		{
			auto sp = std::make_shared<DerivedTy>();
			DerivedTy* result = dynamic_cast<MkEngine::MkActor*>(sp.get());

			if (result not_eq nullptr) {
				m_actors.emplace_back(sp);
			}

			return result;
		}

	public:

		/// <summary> �^�w��̃A�N�^�[���� </summary>
		template< typename T >
		const MkEngine::MkActor* InstantiateActorFromClass()
		{
			return InstantiateActorFromClass_Internal<MkEngine::MkActor, T>();
		}
	};
}