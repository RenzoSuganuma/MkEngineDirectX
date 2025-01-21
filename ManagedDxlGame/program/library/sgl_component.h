#pragma once
#include "memory"
#include "sgl_module.h"
#include "sgl_lang_extention.h"

namespace MkEngine
{
	// 前方定義
	class Actor;

	/// <summary> コンポーネント </summary>
	class Component : public IModule, std::enable_shared_from_this<Component> {
	protected:
		std::shared_ptr<Actor> m_attachedActor;
		bool m_enabled = true;
		using base = Component;

	public:
		DEFCrt_shrd_ptr(Component)

		AutoProperty(bool, Enabled, m_enabled)

		Component();

		~Component();

		// モジュールの初期化
		void Initialize() override;

		// モジュールの更新
		void Update(float delta_time) override;

		// モジュールの描画
		void DrawGraphics() override;

		// モジュールの内での解放
		void MemRelease() override;

		// モジュールの破棄
		void Finalize() override;

		/// <summary> アクターの取得 </summary>
		const std::shared_ptr<Actor> const GetActor() const;

		/// <summary> アクターの割り当て NOTE: thisポインタで渡されるため生ポインター渡し </summary>
		void const SetActor(Actor* actor);
	};
}