#include "vector"
#include "MkModule.h"
#include "MkBehaviour.h"
#include "MkTransform.h"

#pragma once
namespace MkEngine
{
	/// <summary> �Q�[���I�u�W�F�N�g </summary>
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

		/// <summary> �g�����X�t�H�[�������蓖�Ă� </summary>
		void Transform(const MkEngine::MkTransform& transform) {
			m_transform = transform;
		}

		const std::string get_Name() {
			return m_name;
		}

		/// <summary> ���O�����蓖�Ă� </summary>
		void Name(const std::string name) {
			m_name = name;
		}

		/// <summary> �w��̃r�w�C�r�A������΃L���X�g���ĕԂ� </summary>
		/// <typeparam name="T"> �w��̌^ </typeparam>
		/// <returns> �Q�[���I�u�W�F�N�g�ɃA�^�b�`����Ă���r�w�C�r�A </returns>
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

		/// <summary> �r�w�C�r�A��ǉ� </summary>
		/// <typeparam name="T"> �w��̌^ </typeparam>
		/// <param name="behaviour"> �r�w�C�r�A </param>
		template< typename T >
		void AddBehaviour(const T behaviour) {
			m_behaviour.emplace_back(behaviour);
		}

		/// <summary> �r�w�C�r�A���폜���� </summary>
		/// <typeparam name="T"> �w��̌^ </typeparam>
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
