#include "vector"
#include "MkModule.h"
#include "MkGameObject.h"

#pragma once
namespace MkEngine
{
	/// <summary> ƒŒƒxƒ‹ </summary>
	class MkLevel final : public MkEngine::MkModule
	{
	private:
		std::vector< MkEngine::MkGameObject > m_objects;
		using base = MkEngine::MkModule;

	public:

		const MkEngine::MkGameObject& Instantiate() {

		}

		void Initialize() override {
			base::Initialize();
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
