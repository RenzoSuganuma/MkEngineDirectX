﻿#pragma once

#include "list"
#include "memory"
#include "string"

#include "DxLib.h"
#include "sgl_module.h"
#include "sgl_transform.h"
#include "sgl_lang_extention.h"

namespace MkEngine
{
	class Level;
	class Component;

	/// <summary> ゲーム内のオブジェクトとして扱うクラスの基底クラス NOTE: インスタンスはスマートポインタで </summary>
	class Actor : public IModule, std::enable_shared_from_this<Actor> {
	protected:

		/// <summary> コンポーネント </summary>
		std::list<std::shared_ptr<Component>> m_components;
		/// <summary> 配置されたレベル </summary>
		std::shared_ptr<Level> m_placedLevel;
		/// <summary> 配置されたレベル </summary>
		Transform m_transform;
		/// <summary> アクターの名前 </summary>
		std::string m_name = "";
		/// <summary> 有効ならライフサイクルは有効 </summary>
		bool m_enabled = true;
		/// <summary> MkEngine::Actorの別名 </summary>
		using base = Actor;

	public:

		AutoProperty(Transform, Transform, m_transform)

		AutoProperty(std::string, Name, m_name)

		DEFCrt_shrd_ptr(Actor)

		Actor();

		~Actor();

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

		/// <summary> コンポーネントの追加 </summary>
		std::list<std::shared_ptr<Component>>::iterator
			const AddComponent(const std::shared_ptr<Component>& component);

		/// <summary> コンポーネントの削除 </summary>
		void const RemoveComponent(const std::list<std::shared_ptr<Component>>::iterator place);

		/// <summary> レベルの割り当て NOTE: 生ポインタからスマートポインタを生成すつので生ポインタ渡し </summary>
		void const SetPlacedLevel(Level* level);
	};
}
