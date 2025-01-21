#include "DxLib.h"
#include "memory"
#include "gm_main.h"

#include "../MasterKeyEngine/MkActor.h"
#include "../MasterKeyEngine/MkComponent.h"

auto actor = std::make_shared<MkEngine::MkActor>();

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameInit() {
	auto c = actor.get()->AddComponent<MkEngine::MkComponent>();

	actor.get()->Initialize();
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameFixedUpdate(float delta_time) {
	actor.get()->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// 描画処理が実行されます
void gameDrawGraphics() {
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameMemRelease() {
}
