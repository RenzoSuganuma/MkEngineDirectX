#pragma once
#include "memory"
#include "sgl_lang_extention.h"
#include "sgl_module.h"
// 前方定義
class Actor;
/// <summary> コンポーネント </summary>
class Component : public IModule {
protected:
	const Actor* m_attachedActor = nullptr;
	using base = Component;
public:
	DEFCrt_shrd_ptr(Component)
public:
	bool m_enabled = true;

	Component();
	~Component();

	static Component* Create() {
		return new Component;
	}

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
	const Actor* const GetActor() const;
	void const SetActor(const Actor* actor);
};
