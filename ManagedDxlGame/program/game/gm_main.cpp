#include "DxLib.h"
#include "memory"
#include "gm_main.h"
#include "TextPrinter.h"
#include "../library/MKEngine/MasterKeyEngine.h"

auto level = std::make_shared<MkEngine::MkLevel>();
TextPrinter  tp;
MkEngine::MkGameObject obj;
//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameInit() {
	obj = level.get()->Instantiate({tp});
	level.get()->Initialize();
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameFixedUpdate(float delta_time) {
	obj.get_Behaviour< TextPrinter >();

	level.get()->FixedUpdate(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// 描画処理が実行されます
void gameDrawGraphics() {
	level.get()->DrawGraphics();
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameMemRelease() {
	level.get()->MemRelease();
}
