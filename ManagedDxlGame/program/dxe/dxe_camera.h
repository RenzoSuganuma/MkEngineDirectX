#pragma once
#include "../library/tnl_util.h"
#include "../library/tnl_math.h"
#include "../library/tnl_matrix.h"

namespace dxe {

	class Camera {
	public :

		enum class eDimension{ Type2D, Type3D };
		Camera(float screen_w, float screen_h, const eDimension dimension = eDimension::Type3D);
		virtual ~Camera() {}

		TNL_PROPERTY(eDimension, Dimension, dimension_);
		TNL_PROPERTY(float, Angle, angle_);
		TNL_PROPERTY(float, Aspect, aspect_);
		TNL_PROPERTY(float, Near, near_);
		TNL_PROPERTY(float, Far, far_);

		TNL_CALC_PROPERTY(tnl::Vector3, Position, position_);
		TNL_CALC_PROPERTY(tnl::Vector3, Target, target_);
		TNL_CALC_PROPERTY(tnl::Vector3, Upper, up_);

		TNL_PROPERTY(float, PositionX, position_.x);
		TNL_PROPERTY(float, PositionY, position_.y);
		TNL_PROPERTY(float, PositionZ, position_.z);
		TNL_PROPERTY(float, TargetX, target_.x);
		TNL_PROPERTY(float, TargetY, target_.y);
		TNL_PROPERTY(float, TargetZ, target_.z);
		TNL_PROPERTY(float, UpperX, up_.x);
		TNL_PROPERTY(float, UpperY, up_.y);
		TNL_PROPERTY(float, UpperZ, up_.z);

		// スクリーンの幅
		float getScreenWidth() { return screen_w_; }
		// スクリーンの高さ
		float getScreenHeight() { return screen_h_; }

		// ビュー行列の取得
		const tnl::Matrix& getViewMatrix() const noexcept { return view_; }
		// プロジェクション行列の取得
		const tnl::Matrix& getProjectionMatrix() const noexcept { return proj_; }

		// 正面ベクトルの取得
		virtual inline tnl::Vector3 forward() { return tnl::Vector3::Normalize(target_ - position_); }
		// 右ベクトルの取得
		virtual inline tnl::Vector3 left() { return tnl::Vector3::Cross(forward(), { 0, 1, 0 }); }
		// 右ベクトルの取得
		virtual inline tnl::Vector3 right() { return tnl::Vector3::Cross({ 0, 1, 0 }, forward()); }
		// 後方ベクトルの取得
		virtual inline tnl::Vector3 back() { return tnl::Vector3::Normalize(position_ - target_); }


		//----------------------------------------------------------------------------------------------
		// work... ゲーム空間座標をスクリーン座標へ変換
		// arg1... ゲーム空間座標
		// arg2... カメラ座標の影響をどれだけ受けるか
		// ret.... スクリーン座標
		// tips... 2D カメラ用
		tnl::Vector3 convertWorldToScreenPosition2D( const tnl::Vector3& world_position, float affect_weight = 1.0f );

		//----------------------------------------------------------------------------------------------
		// work... スクリーン座標をゲーム空間座標へ変換
		// arg1... スクリーン座標
		// ret.... ゲーム空間座標
		// tips... 2D カメラ用
		tnl::Vector3 convertScreenToWorldPosition2D( const tnl::Vector3& screen_position );


		//----------------------------------------------------------------------------------------------
		// work... 視錐台平面の法線を取得する
		// arg1... 6つの平面のどれか
		// ret.... 視錐台平面の法線
		// tips... 3D カメラ用
		enum class eFlustum { Left, Right, Bottom, Top, Near, Far, Max };
		tnl::Vector3 getFlustumNormal(eFlustum flusum) ;

		// 更新
		void update() ;

		// デバッグ用 カメラ描画
		// arg1... スケール
		// arg2... 色
		// tips... 3D 用
		void render(float scale, uint32_t color = 0xffffff00) const ;

	protected :
		Camera() {}
		eDimension dimension_ = eDimension::Type3D;

		tnl::Matrix view_;
		tnl::Matrix proj_;

		// カメラの３次元座標
		tnl::Vector3 position_;
		// カメラが３次元のどこを画面の中央にとらえているか
		tnl::Vector3 target_;
		// カメラの『上』を定義するアッパーベクトル
		tnl::Vector3 up_ = tnl::Vector3(0, 1, 0);

		// カメラの画角 ( 度 )
		float angle_ = tnl::ToRadian(60.0f);
		// カメラのアスペクト比 ( 縦横比 )
		float aspect_ = 1.0f;
		// カメラに映る範囲の最近距離
		float near_ = 1.0f;
		// カメラに映る範囲の最遠距離
		float far_ = 50000.0f;

		float screen_w_ = 0;
		float screen_h_ = 0;

	};

}
