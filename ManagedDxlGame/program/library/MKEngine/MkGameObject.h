#include "MkModule.h"
#include "MkTransform.h"

#pragma once
namespace MkEngine
{
	/// <summary> ゲームオブジェクト </summary>
	class MkGameObject final : public MkEngine::MkModule
	{
	private:
		using base = MkEngine::MkModule;
		MkEngine::MkTransform m_transform;

	public:
		const MkEngine::MkTransform& get_Transform()
		{
			return m_transform;
		}

		void Initialize() override {
			base::Initialize();
		}

		void Update() override {
			base::Update();
		}

		void FixedUpdate(float deltaTime) override {
			base::FixedUpdate(deltaTime);
		}

		void DrawGraphics() override {
			base::DrawGraphics();
		}

		void MemRelease() override {
			base::MemRelease();
		}
	};
}
