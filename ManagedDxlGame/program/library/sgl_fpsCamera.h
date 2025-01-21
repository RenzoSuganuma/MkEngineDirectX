#pragma once

#include "sgl.h"
#include "functional"
#include "../dxe/dxe.h"
#include "tnl_vector3.h"

namespace MkEngine
{
	// FPS�J����
	class FPSCamera : public dxe::Camera, IModule {
	private:
		bool m_isFreelook = true;
		tnl::Quaternion m_rotation;

	public:
		DEFCrt_shrd_ptr(FPSCamera)

			FPSCamera() {};
		FPSCamera(float screen_w, float screen_h) : dxe::Camera(screen_w, screen_h) {}

		void SetFreeLookMode(bool isFreelook) {
			m_isFreelook = isFreelook;
		}

		// ���W���[���̏�����
		void Initialize() override {
		}

		// ���W���[���̍X�V
		void Update(float delta_time) override {
			if (m_isFreelook and tnl::Input::IsMouseDown(tnl::Input::eMouse::RIGHT)) {
				// �p�����X�V
				tnl::Input::RunIndexKeyDown(
					[&](uint32_t ind) {
						tnl::Vector3 v[6] = {
							left(),
							right(),
							forward().xz(),
							back().xz(),
							up().xy(),
							-up().xy()
						};
						addPosition(v[ind] * 3.0f);

					}, eKeys::KB_A, eKeys::KB_D, eKeys::KB_W, eKeys::KB_S, eKeys::KB_E, eKeys::KB_Q);
				auto vlook = tnl::Input::GetMouseVelocity();
				m_rotation *= tnl::Quaternion::RotationAxis({ 0,1,0 }, tnl::ToRadian(vlook.x * 0.1f));
				m_rotation *= tnl::Quaternion::RotationAxis(right(), tnl::ToRadian(vlook.y * 0.1f));

				// �p���p�����[�^����^�[�Q�b�g���W�ƃA�b�p�[�x�N�g�����v�Z
				target_ = position_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, m_rotation);
				up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, m_rotation);
			}
			Camera::update();
		}

		// ���W���[���̕`��
		void DrawGraphics() override {}

		// ���W���[���̓��ł̉��
		void MemRelease() override {}

		// ���W���[���̔j��
		void Finalize() override {}

		inline tnl::Vector3 up() {
			up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, m_rotation);
			return up_;
		}

		inline tnl::Vector3 down() { return -up(); }

		inline tnl::Vector3 forward() override {
			target_ = position_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, m_rotation);
			return tnl::Vector3::Normalize(target_ - position_);
		}

		inline tnl::Vector3 back() override { return -forward(); }

		inline tnl::Vector3 left() override { return tnl::Vector3::Cross(forward(), up()); }

		inline tnl::Vector3 right() override { return tnl::Vector3::Cross(up(), forward()); }
	};
}
