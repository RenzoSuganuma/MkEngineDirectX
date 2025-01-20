#include "DxLib.h"
#include "memory"
#include "gm_main.h"
#include "../library/sgl.h"

#include "TestActor.h"
#include "TestComponent.h"

auto level = std::make_shared<Level>();
auto obj = std::make_shared<TestActor>(  );
auto component = std::make_shared<TestComponent>();
auto cam = std::make_shared<FPSCamera>( DXE_WINDOW_WIDTH_F, DXE_WINDOW_HEIGHT_F );

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameInit() {
	obj.get()->AddComponent(component);

	level.get()->AddActor(obj);

	level.get()->Initialize();
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameFixedUpdate(float delta_time) {
	level.get()->Update(delta_time);
	cam.get()->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// 描画処理が実行されます
void gameDrawGraphics() {
	dxe::DrawGridGround(cam, 50, 20, -1);
	level.get()->DrawGraphics();
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameMemRelease() {
	level.get()->MemRelease();
}
