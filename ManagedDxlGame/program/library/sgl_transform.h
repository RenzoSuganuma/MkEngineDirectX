#include "sgl_object.h"
#include "tnl_vector3.h"
#include "tnl_quaternion.h"
#include "sgl_lang_extention.h"

#pragma once

namespace MkEngine
{
	/// <summary> トランスフォーム </summary>
	class Transform : public Object
	{
	private:
		tnl::Vector3 m_position;
		tnl::Quaternion m_rotation;

	public:
		AutoProperty(tnl::Vector3, Position, m_position)
			AutoProperty(tnl::Quaternion, Rotation, m_rotation)

			void RotateAxis(const tnl::Vector3& axis, float angle) {
			m_rotation *= tnl::Quaternion::RotationAxis(axis, angle);
		}
	};
}
