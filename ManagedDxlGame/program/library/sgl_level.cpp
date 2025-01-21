#include "string"
#include "../dxe/dxe.h"
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_level.h"

namespace MkEngine
{
	Level::Level() {}
	Level::~Level() {}

	void  Level::Initialize()
	{
		auto itr = m_actors.begin();
		while (itr != m_actors.end())
		{
			(*itr)->Initialize();
			itr++;
		}
	}

	void  Level::Update(float deltaTime)
	{
		auto itr = m_actors.begin();
		while (itr != m_actors.end())
		{
			(*itr)->Update(deltaTime);
			itr++;
		}
	}

	void  Level::DrawGraphics()
	{
		auto itr = m_actors.begin();
		while (itr != m_actors.end())
		{
			(*itr)->DrawGraphics();
			itr++;
		}
	}

	void  Level::Finalize()
	{
		auto it = m_actors.begin();
		while (it != m_actors.end())
		{
			(*it)->Finalize();
			++it;
		}
	}

	void  Level::MemRelease()
	{
		auto it = m_actors.begin();
		while (it != m_actors.end())
		{
			(*it)->MemRelease();
			++it;
		}
		// m_actors.clear();
	}

	void Level::DrawActorList()
	{
		auto count_str = (std::to_string(m_actors.size()) + "Actors");

		DxLib::DrawString(DXE_WINDOW_WIDTH - 200, 30, count_str.c_str(), -1);
		auto c = m_actors.begin();
		for (int i = 1; i <= m_actors.size(); i++) {
			DxLib::DrawString(DXE_WINDOW_WIDTH - 200, 50 + (15 * i),
				(std::to_string(i) + ":" + (*c)->getName()).c_str()
				, -1);
			c++;
		}
	}

	const std::list< std::shared_ptr<Actor> >::iterator
		const Level::AddActor(const std::shared_ptr<Actor>& obj)
	{
		obj.get()->SetPlacedLevel(this);
		m_actors.emplace_back(obj.get());
		auto it = m_actors.end();
		it--;
		return it;
	}

	void const Level::RemoveActor(const std::shared_ptr<Actor>& obj)
	{
		m_actors.remove(obj);
	}
}
