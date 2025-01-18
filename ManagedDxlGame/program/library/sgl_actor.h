#pragma once
#include "list"
#include "memory"
#include "string"
#include "DxLib.h"
#include  "sgl_module.h"
#include "sgl_transform.h"
#include "sgl_lang_extention.h"

class Level;
class Component;

/// <summary> ゲーム内のオブジェクトとして扱うクラスの基底クラスインスタンスはスマートポインタで </summary>
class Actor : public IModule {
protected:
	std::list< Component* > m_components;
	Transform m_transform;
	Level* m_placedLevel = nullptr;
	std::string m_name = "";
	bool m_enabled = true;
public:
	// モジュールの初期化
	void Initialize() override;
	// モジュールの更新
	void Update(float delta_time) override;
	// モジュールの描画
	void Draw() override;
	// モジュールの内での解放
	void MemRelease() override;
	// モジュールの破棄
	void Finalize() override;
	/* auto properties */
public:
	AutoProperty(Transform, Transform, m_transform)
	AutoProperty(std::string, Name, m_name)
	DEFCrt_shrd_ptr(Actor)
public:

	Actor();
	~Actor();

	/* statics */
	static Actor* Create() {
		return new Actor;
	}

	std::list< Component* >::iterator
		const AddComponent(Component* component);
	void const RemoveComponent(const std::list<Component*>::iterator place);
	void const SetPlacedLevel(const Level* level);
	/* templates */
	template<typename T>
	static T GetComponent(const Actor* getComponentFrom)
	{
		auto it = getComponentFrom->m_components.begin();
		while (it != getComponentFrom->m_components.end())
		{
			auto r = static_cast<T>(*it);
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
