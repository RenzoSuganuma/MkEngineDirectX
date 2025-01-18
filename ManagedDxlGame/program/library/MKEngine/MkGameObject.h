#include "vector"
#include "MkModule.h"
#include "MkBehaviour.h"
#include "MkTransform.h"

#pragma once
namespace MkEngine
{
	/// <summary> ゲームオブジェクト </summary>
	class MkGameObject final : public MkEngine::MkModule
	{
	private:
		using base = MkEngine::MkModule;
		std::string m_name;
		MkEngine::MkTransform m_transform;
		std::vector< MkEngine::MkBehaviour > m_behaviour;

	public:
		const MkEngine::MkTransform& get_Transform()
		{
			return m_transform;
		}

		/// <summary> トランスフォームを割り当てる </summary>
		void Transform(const MkEngine::MkTransform& transform) {
			m_transform = transform;
		}

		const std::string get_Name() {
			return m_name;
		}

		/// <summary> 名前を割り当てる </summary>
		void Name(const std::string name) {
			m_name = name;
		}

		/// <summary> 指定のビヘイビアがあればキャストして返す </summary>
		/// <typeparam name="T"> 指定の型 </typeparam>
		/// <returns> ゲームオブジェクトにアタッチされているビヘイビア </returns>
		template< typename T >
		const T& get_Behaviour() {
			for (auto b : m_behaviour) {
				auto result = dynamic_cast<T>(b);
				if (result != nullptr) {
					return result;
				}
				else {
					return nullptr;
				}
			}
		}

		/// <summary> ビヘイビアを追加 </summary>
		/// <typeparam name="T"> 指定の型 </typeparam>
		/// <param name="behaviour"> ビヘイビア </param>
		template< typename T >
		void AddBehaviour(const T behaviour) {
			m_behaviour.emplace_back(behaviour);
		}

		/// <summary> ビヘイビアを削除する </summary>
		/// <typeparam name="T"> 指定の型 </typeparam>
		template< typename T >
		void RemoveBehaviour() {

			auto i = m_behaviour.begin();
			while (i != m_behaviour.end()) {
				auto result = dynamic_cast<T>(*i);
				if (result != nullptr) {
					m_behaviour.erase(i);
					break;
				}

				i++;
			}
		}

		void Initialize() override {
			base::Initialize();

			for (auto b : m_behaviour) {
				b.Initialize();
			}
		}

		void FixedUpdate(float deltaTime) override {
			base::FixedUpdate(deltaTime);

			for (auto b : m_behaviour) {
				b.FixedUpdate(deltaTime);
			}
		}

		void DrawGraphics() override {
			base::DrawGraphics();

			for (auto b : m_behaviour) {
				if (b.get_BehaviourType() == MkEngine::MkBehaviourType::Graphics) {
					b.DrawGraphics();
				}
			}
		}

		void MemRelease() override {
			base::MemRelease();

			for (auto b : m_behaviour) {
				b.MemRelease();
			}
		}
	};
}
