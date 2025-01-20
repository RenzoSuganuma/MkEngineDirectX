#pragma once
#include "list"
#include "memory"
#include "string"
#include "DxLib.h"
#include "sgl_module.h"
#include "sgl_transform.h"
#include "sgl_lang_extention.h"

class Level;
class Component;

/// <summary> ゲーム内のオブジェクトとして扱うクラスの基底クラスインスタンスはスマートポインタで </summary>
class Actor : public IModule , std::enable_shared_from_this<Actor> {
protected:
	std::list<std::shared_ptr<Component>> m_components;
	std::shared_ptr<Level> m_placedLevel;

	Transform m_transform;
	std::string m_name = "";
	bool m_enabled = true;
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
	void const SetPlacedLevel(Level * level);

	/// <summary> コンポーネントの取得 </summary>
	template<typename T>
	static T GetComponent(const std::shared_ptr<Actor>& getComponentFrom)
	{
		auto it = getComponentFrom->m_components.begin();
		while (it != getComponentFrom->m_components.end())
		{
			auto r = static_cast<T>((*it).get());
			if (r != nullptr)
			{
				return r;
				break;
			}
			it++;
		}
		return nullptr;
	}
};
