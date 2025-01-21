#pragma once
#include "list"
#include "memory"
#include "sgl_module.h"
#include "sgl_lang_extention.h"

namespace MkEngine
{
	// 前方定義
	class Actor;

	// Unityでいうシーン、すべてのアクタが存在するクラス。
	class Level : IModule, std::enable_shared_from_this<Level> {
	private:
		std::list<std::shared_ptr<Actor>> m_actors;
	public:
		Level();
		~Level();

		DEFCrt_shrd_ptr(Level)

	public:
		void  Initialize() override;

		void  Update(float deltaTime) override;

		void  DrawGraphics() override;

		void  Finalize() override;

		void  MemRelease() override;

		void DrawActorList();
		const std::list< std::shared_ptr<Actor> >::iterator
			const AddActor(const std::shared_ptr<Actor>& obj);

		void const RemoveActor(const std::shared_ptr<Actor>& obj);
	};
}