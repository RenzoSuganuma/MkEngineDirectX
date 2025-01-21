#pragma once

#include "sgl.h"
#include "functional"
#include "../dxe/dxe.h"
#include "tnl_vector3.h"

namespace MkEngine
{
	// FPSカメラ
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

		// モジュールの初期化
		void Initialize() override {
		}

		// モジュールの更新
		void Update(float delta_time) override {
			if (m_isFreelook and tnl::Input::IsMouseDown(tnl::Input::eMouse::RIGHT)) {
				// 姿勢を更新
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

				// 姿勢パラメータからターゲット座標とアッパーベクトルを計算
				target_ = position_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, m_rotation);
				up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, m_rotation);
			}
			Camera::update();
		}

		// モジュールの描画
		void DrawGraphics() override {}

		// モジュールの内での解放
		void MemRelease() override {}

		// モジュールの破棄
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
