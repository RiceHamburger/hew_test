//==================================================
//  タイトル画面のクラス [TitleScene.cpp]     Autor:ロ
//==================================================
#include "TitleScene.h"
#include "texture.h"
#include "D3DInput.h"
#include "SceneManager.h"
#include "sound.h"
#include "fade.h"

// コンストラクタ
//==================================================
TitleScene::TitleScene() {
	m_UI = new Sprite();

	countTime = TITLE_TIME;
	btn_alpha = TITLETEXT_ALPHA;
	startFadeInOut = false;
	PlaySound(SOUND_LABEL_BGM000);

	g_Fade->init();
}

// デストラクタ
//==================================================
TitleScene::~TitleScene() {}

void TitleScene::Update() {
	static float timeElapsed = 0.0f;

	if (!startFadeInOut) {
		if (gDInput->keyIsTrigger(DIK_SPACE)) {
			PlaySound(SOUND_LABEL_SE_KEYDOWN);

			//タイトル画面からゲーム画面に
			//1000 = 一秒
			g_Fade->Fade_Start(true, 500, D3DCOLOR_RGBA(0, 0, 0, 255));

			//フェイトイン開始
			startFadeInOut = true;
		}
	}

	if (startFadeInOut && !g_Fade->Fade_IsFade()) {
		//タイトルの音声を止める
		StopSound(SOUND_LABEL_BGM000);

		delete m_UI;

		//フェイトイン終了
		startFadeInOut = false;

		//ゲーム画面にいく
		SceneManager::ChangeScene(SceneManager::GAME);

	}

	//press btn shining
	countTime--;

	if (countTime <= 0) {
		if (btn_alpha == TITLETEXT_ALPHA) {
			btn_alpha = 0;
		}
		else {
			btn_alpha = TITLETEXT_ALPHA;
		}
		countTime = TITLE_TIME;
	}
}

//描画処理
//==================================================
void TitleScene::Draw() {
	m_UI->Sprite_Draw(TITLE, (SCREEN_WIDTH - Texture_GetWidth(TITLE)) / 2, (SCREEN_HEIGHT - Texture_GetHeight(TITLE)) / 3);
	m_UI->Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, btn_alpha));
	m_UI->Sprite_Draw(TITLEBTN, (SCREEN_WIDTH - Texture_GetWidth(TITLEBTN)) / 2, SCREEN_HEIGHT / 2 + 280);
	m_UI->Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
}

//前回デバイス処理
//==================================================
void TitleScene::LostDevice() {
	
}

//デバイスをリセット処理
//==================================================
void TitleScene::ResetDevice() {

}