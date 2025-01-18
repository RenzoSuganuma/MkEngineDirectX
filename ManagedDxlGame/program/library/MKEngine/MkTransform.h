#include "tnl_vector3.h"
#include "tnl_quaternion.h"

#pragma once
namespace MkEngine
{
	/// <summary> トランスフォーム </summary>
	class MkTransform final
	{
	private:
		tnl::Vector3 m_position;
		tnl::Quaternion m_rotation;

	public:
		const tnl::Vector3& get_Position() 
		{
			return m_position;
		}

		void set_Position(const tnl::Vector3& pos) 
		{
			m_position = pos;
		}

		const tnl::Quaternion& get_Rotation() 
		{
			return m_rotation;
		}

		void set_Rotation(const tnl::Quaternion& rot) 
		{
			m_rotation = rot;
		}
	};
}
