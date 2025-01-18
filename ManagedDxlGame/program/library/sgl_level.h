#pragma once
#include "list"
#include "memory"
#include "sgl_fpsCamera.h"
#include "sgl_lang_extention.h"
#include "sgl_module.h"
// 前方定義
class Actor;
// Unityでいうシーン、すべてのアクタが存在するクラス。
class Level final : IModule {
private:
	std::list< Actor* > m_actors;
public:
	Level();
	~Level();

	static Level* Create() {
		return new Level;
	}

	DEFCrt_shrd_ptr(Level)
public:
	void  Initialize() override;
	void  Update(float deltaTime) override;
	void  DrawGraphics() override;
	void  Finalize() override;
	void  MemRelease() override;

	void DrawActorList();
	const std::list< Actor* >::iterator
		const AddActor(const Actor* obj);
	void const RemoveActor(const Actor* obj);
	void const RemoveActor(const std::list< Actor* >::iterator place);
};
