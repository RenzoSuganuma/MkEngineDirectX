#include "tnl_vector3.h"
#include "tnl_quaternion.h"
#include "sgl_lang_extention.h"

#pragma once
/// <summary> �g�����X�t�H�[�� </summary>
class Transform
{
private:
	tnl::Vector3 m_position;
	tnl::Quaternion m_rotation;

public:
	AutoProperty(tnl::Vector3, Position, m_position)
	AutoProperty(tnl::Quaternion, Rotation, m_rotation)
};

