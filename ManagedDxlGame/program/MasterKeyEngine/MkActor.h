#pragma once

#include "memory"
#include "concepts"

#include "../library/sgl_actor.h"
#include "MkComponent.h"

namespace MkEngine
{
	/// <summary> MkEngine::Actor ラッパー </summary>
	struct MkActor : public Actor
	{
	private:

		/// <summary> コンポーネントの追加 NOTE:型制約あり </summary>
		template< typename BaseTy, typename DerivedTy >
			requires std::derived_from<DerivedTy, BaseTy>
		const MkEngine::MkComponent* AddComponent_Internal()
		{
			auto sp = std::make_shared<DerivedTy>();
			DerivedTy* result = dynamic_cast<MkEngine::MkComponent*>(sp.get());

			if (result not_eq nullptr) {
				m_components.emplace_back(sp);
			}

			return result;
		}

		/// <summary> コンポーネントの取得 NOTE:型制約あり </summary>
		template<typename BaseTy, typename DerivedTy>
			requires std::derived_from<DerivedTy, BaseTy>
		const DerivedTy* GetComponent_Internal()
		{
			auto i = m_components.begin();
			while (i != m_components.end())
			{
				auto r = dynamic_cast<DerivedTy*>((*i).get());
				if (r not_eq nullptr)
				{
					return r;
					break;
				}
				i++;
			}

			return nullptr;
		}

	public:
		MkActor() {}
		~MkActor() {}

		/// <summary> コンポーネントの追加 </summary>
		template< typename T >
		const MkEngine::MkComponent* const AddComponent()
		{
			return AddComponent_Internal<MkEngine::MkComponent, T>();
		}

		/// <summary> コンポーネントの取得 </summary>
		template<typename T>
		const T* const GetComponent()
		{
			return GetComponent_Internal<MkEngine::MkComponent, T>();
		}

		/// <summary> コンポーネントの削除 </summary>
		void const RemoveComponent(int index)
		{
			auto i = m_components.begin();
			for (size_t i = 0; i < index; i++)
			{
				i++;
			}

			MkEngine::Actor::RemoveComponent(i);
		}
	};
}