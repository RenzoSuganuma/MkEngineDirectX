#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_component.h"

Component::Component() {}

Component::~Component() {}

void Component::Initialize()
{
	m_enabled = true;
}

void Component::Update(float deltaTime)
{
}

void Component::Finalize()
{
	m_attachedActor = nullptr;
	m_enabled = false;
}

void Component::DrawGraphics()
{
}

void Component::MemRelease()
{
}

const std::shared_ptr<Actor> const Component::GetActor() const
{
	return m_attachedActor;
}

void const Component::SetActor(Actor * actor)
{
	m_attachedActor.reset(actor);
}

