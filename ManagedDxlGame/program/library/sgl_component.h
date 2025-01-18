#pragma once
#include "memory"
#include "sgl_module.h"
#include "sgl_lang_extention.h"

// 前方定義
class Actor;

/// <summary> コンポーネント </summary>
class Component : public IModule {
protected:
	const Actor* m_attachedActor = nullptr;
	bool m_enabled = true;
	using base = Component;

public:
	DEFCrt_shrd_ptr(Component)

	AutoProperty(bool , Enabled , m_enabled)

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
	void DrawGraphics() override;

	// モジュールの内での解放
	void MemRelease() override;

	// モジュールの破棄
	void Finalize() override;

	const Actor* const GetActor() const;

	void const SetActor(const Actor* actor);
};
