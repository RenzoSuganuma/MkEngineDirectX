﻿#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_component.h"
#include "sgl_level.h"

namespace MkEngine
{
	Actor::Actor() {}

	Actor::~Actor() {}

	void Actor::Initialize()
	{
		auto it = m_components.begin();
		while (it != m_components.end())
		{
			(*it)->Initialize();
			it++;
		}
		m_enabled = true;
	}

	void Actor::Update(float deltaTime)
	{
		auto it = m_components.begin();
		while (it != m_components.end())
		{
			(*it)->Update(deltaTime);
			it++;
		}
	}

	void Actor::DrawGraphics()
	{
		auto it = m_components.begin();
		while (it != m_components.end())
		{
			(*it)->DrawGraphics();
			it++;
		}
	}

	void Actor::MemRelease()
	{
		auto it = m_components.begin();
		while (it != m_components.end())
		{
			(*it)->MemRelease();
			it++;
		}
		m_components.clear();
	}

	void Actor::Finalize()
	{
		auto it = m_components.begin();
		while (it != m_components.end())
		{
			(*it)->Finalize();
			it++;
		}
		m_enabled = false;
		m_placedLevel = nullptr;
	}

	std::list<std::shared_ptr<Component>>::iterator
		const Actor::AddComponent(const std::shared_ptr<Component>& component)
	{
		component->SetActor(this);
		m_components.emplace_back(component);
		auto it = m_components.end();
		it--;
		return it;
	}

	void const Actor::RemoveComponent(const std::list<std::shared_ptr<Component>>::iterator place)
	{
		m_components.erase(place);
	}

	void const Actor::SetPlacedLevel(Level* level)
	{
		m_placedLevel.reset(level);
	}
}
