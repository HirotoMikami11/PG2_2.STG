#include "SceneChange.h"

SceneChange::SceneChange() {
	isStartChange_ = false;

	isEndChange_ = false;

	isGameClear_ = false;
	isGameOver_ = false;

	//暗幕変数(blackoutCurtainと呼称	BC)
	CT_ = 0;
	addCT_ = 0;

	CEaseTimer_ = 51;
	CEaseDir_ = 1;
	maxCColor_ = 0xff;
	minCColor_ = 0x0;
	addCColor_ = 0x0;
	CColor_ = 0x00000000;



	CWaitMaxTimer_ = 60;
	CWaitTimer_ = CWaitMaxTimer_;

	/*チュートリアルからゲーム本編の暗転変数*/
	CtoGT_ = 0;
	addCtoGT_ = 0;

	CtoGEaseTimer_ = 51;
	CtoGEaseDir_ = 1;
	maxCtoGColor_ = 0xff;
	minCtoGColor_ = 0x0;
	addCtoGColor_ = 0x0;
	CtoGColor_ = 0x00000000;
}

SceneChange::~SceneChange() {

}

void SceneChange::Reset() {
	/*
	isStartChange_ = false;
	isEndChange_ = false;
	*/
	isGameClear_ = false;
	isGameOver_ = false;
	//暗幕変数(blackoutCurtainと呼称	BC)
	CT_ = 0;
	addCT_ = 0;
	CEaseTimer_ = 51;
	CEaseDir_ = 1;
	maxCColor_ = 0xff;
	minCColor_ = 0x0;
	addCColor_ = 0x0;
	CColor_ = 0x00000000;

	CWaitMaxTimer_ = 60;
	CWaitTimer_ = CWaitMaxTimer_;


	/*チュートリアルからゲーム本編の暗転変数*/
	CtoGT_ = 0;
	addCtoGT_ = 0;

	CtoGEaseTimer_ = 51;
	CtoGEaseDir_ = 1;
	maxCtoGColor_ = 0xff;
	minCtoGColor_ = 0x0;
	addCtoGColor_ = 0x0;
	CtoGColor_ = 0x00000000;
}






void SceneChange::Update() {
	switch (Scene::SceneNum_) {
	case 0:
		if (!isStartChange_ && !isEndChange_) {
			Reset();
		}
#pragma region"シーン開始処理"
		if (!isEndChange_ && isStartChange_) {
			//足す透明度をイージング
			CT_ += (1.0f / (CEaseTimer_ / 3.0f)) * CEaseDir_;
			addCT_ = easeInOutExpo(CT_);
			addCColor_ = (1 - addCT_) * minCColor_ + addCT_ * maxCColor_;
			if (CT_ <= 0.0f) {
				CT_ = 0.0f;
				isStartChange_ = false;//暗幕の透明度を変化させるフラグを下す
			}

			if (addCColor_ >= 0xFF) {
				addCColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			if (addCColor_ <= 0x10) {
				addCColor_ = 0x00;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CColor_ = 0x00000000 + int(addCColor_);//ここで透明度を足す
		}
#pragma endregion
#pragma region"終了処理"

		//足す透明度をイージング
		if (!isStartChange_ && isEndChange_) {
			CT_ += (1.0f / (CEaseTimer_ / 2.0f)) * CtoGEaseDir_;
			addCT_ = easeInCubic(CT_);
			addCColor_ = (1 - addCT_) * minCColor_ + addCT_ * maxCColor_;
			if (CT_ >= 1.0f) {
				CT_ = 1.0f;
				CWaitTimer_ -= 1;
				if (CWaitTimer_ == 0) {
					isEndChange_ = false;//暗幕の透明度を変化させるフラグを下す
					isStartChange_ = true;
					CEaseDir_ *= -1;
					Scene::SceneNum_ = 1;
				}
			}
			if (addCColor_ >= 0xFF) {
				addCColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CColor_ = 0x00000000 + int(addCColor_);//ここで透明度を足す

		}
#pragma endregion

		break;

	case 1:

		if (!isStartChange_ && !isEndChange_) {
			Reset();
		}
#pragma region"シーン開始処理"
		if (!isEndChange_ && isStartChange_) {
			//足す透明度をイージング
			CT_ += (1.0f / (CEaseTimer_ / 3.0f)) * CEaseDir_;
			addCT_ = easeInOutExpo(CT_);
			addCColor_ = (1 - addCT_) * minCColor_ + addCT_ * maxCColor_;
			if (CT_ <= 0.0f) {
				CT_ = 0.0f;
				isStartChange_ = false;//暗幕の透明度を変化させるフラグを下す
			}

			if (addCColor_ >= 0xFF) {
				addCColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			if (addCColor_ <= 0x10) {
				addCColor_ = 0x00;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CColor_ = 0x00000000 + int(addCColor_);//ここで透明度を足す
		}
#pragma endregion

#pragma region"シーン終了処理"

		//足す透明度をイージング
		if (!isStartChange_ && isEndChange_) {
   			CtoGT_ += (1.0f / (CtoGEaseTimer_ * 1.5f)) * CtoGEaseDir_;
			addCtoGT_ = easeInCubic(CtoGT_);
			addCtoGColor_ = (1 - addCtoGT_) * minCtoGColor_ + addCtoGT_ * maxCtoGColor_;
			if (CtoGT_ >= 1.0f) {
				CtoGT_ = 1.0f;
				CWaitTimer_ -= 1;
				if (CWaitTimer_ <= 0) {
					CWaitTimer_ = CWaitMaxTimer_;
					isEndChange_ = false;//暗幕の透明度を変化させるフラグを下す
					isStartChange_ = true;
					CtoGEaseDir_ *= -1;
					if (isGameClear_) {
						Scene::SceneNum_ = 2;
					} else if (isGameOver_) {
						Scene::SceneNum_ = 3;

					}
				}
			}
			if (addCtoGColor_ >= 0xFF) {
				addCtoGColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CtoGColor_ = 0x00000000 + int(addCtoGColor_);//ここで透明度を足す


		}

#pragma endregion
		break;

	case 2:

#pragma region"シーン開始処理"
		if (!isEndChange_ && isStartChange_) {
			//足す透明度をイージング
			CtoGT_ += (1.0f / (CtoGEaseTimer_ / 2.0f)) * CtoGEaseDir_;
			addCtoGT_ = easeInOutExpo(CtoGT_);
			addCtoGColor_ = (1 - addCtoGT_) * minCtoGColor_ + addCtoGT_ * maxCtoGColor_;
			if (CtoGT_ <= 0.0f) {
				CtoGT_ = 0.0f;
				isStartChange_ = false;//暗幕の透明度を変化させるフラグを下す
			}

			if (addCtoGColor_ >= 0xFF) {
				addCtoGColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			if (addCtoGColor_ <= 0x10) {
				addCtoGColor_ = 0x00;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CtoGColor_ = 0x00000000 + int(addCtoGColor_);//ここで透明度を足す
		}
#pragma endregion

#pragma region"終了処理"

		//足す透明度をイージング
		if (!isStartChange_ && isEndChange_) {
			CT_ += (1.0f / (CEaseTimer_ / 2.0f)) * CEaseDir_;
			addCT_ = easeInCubic(CT_);
			addCColor_ = (1 - addCT_) * minCColor_ + addCT_ * maxCColor_;
			if (CT_ >= 1.0f) {
				CT_ = 1.0f;
				CWaitTimer_ -= 1;
				if (CWaitTimer_ == 0) {
					isEndChange_ = false;//暗幕の透明度を変化させるフラグを下す
					isStartChange_ = true;
					CEaseDir_ *= -1;
					Scene::SceneNum_ = 0;
				}
			}
			if (addCColor_ >= 0xFF) {
				addCColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CColor_ = 0x00000000 + int(addCColor_);//ここで透明度を足す

		}
#pragma endregion
		break;

	case 3:
		if (!isStartChange_ && !isEndChange_) {
			Reset();
		}
#pragma region"シーン開始処理"
		if (!isEndChange_ && isStartChange_) {
			//足す透明度をイージング
			CtoGT_ += (1.0f / (CtoGEaseTimer_ / 2.0f)) * CtoGEaseDir_;
			addCtoGT_ = easeInOutExpo(CtoGT_);
			addCtoGColor_ = (1 - addCtoGT_) * minCtoGColor_ + addCtoGT_ * maxCtoGColor_;
			if (CtoGT_ <= 0.0f) {
				CtoGT_ = 0.0f;
				isStartChange_ = false;//暗幕の透明度を変化させるフラグを下す
			}

			if (addCtoGColor_ >= 0xFF) {
				addCtoGColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			if (addCtoGColor_ <= 0x10) {
				addCtoGColor_ = 0x00;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CtoGColor_ = 0x00000000 + int(addCtoGColor_);//ここで透明度を足す
		}
#pragma endregion

#pragma region"終了処理"

		//足す透明度をイージング
		if (!isStartChange_ && isEndChange_) {
			CT_ += (1.0f / (CEaseTimer_ / 2.0f)) * CEaseDir_;
			addCT_ = easeInCubic(CT_);
			addCColor_ = (1 - addCT_) * minCColor_ + addCT_ * maxCColor_;
			if (CT_ >= 1.0f) {
				CT_ = 1.0f;
				CWaitTimer_ -= 1;
				if (CWaitTimer_ == 0) {
					isEndChange_ = false;//暗幕の透明度を変化させるフラグを下す
					isStartChange_ = true;
					CEaseDir_ *= -1;
					Scene::SceneNum_ = 0;
				}
			}
			if (addCColor_ >= 0xFF) {
				addCColor_ = 0xFF;//バウンドで色がオーバーフローしないように上限で無理やり止める
			}
			CColor_ = 0x00000000 + int(addCColor_);//ここで透明度を足す

		}
#pragma endregion
		break;

	default:
		break;
	}

	if (CColor_ >= 0x000000FF) {
		CColor_ = 0x000000FF;
	} else if (CColor_ <= 0x00000000) {
		CColor_ = 0x00000000;
	}
	if (CtoGColor_ >= 0x000000FF) {
		CtoGColor_ = 0x000000FF;
	} else if (CtoGColor_ <= 0x00000000) {
		CtoGColor_ = 0x00000000;
	}
}

void SceneChange::Draw() {
	switch (Scene::SceneNum_) {
	case 0:
		if (isStartChange_ || isEndChange_) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CColor_, kFillModeSolid);


		}
		break;
	case 1:

		if (isStartChange_ || isEndChange_) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CColor_, kFillModeSolid);
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CtoGColor_, kFillModeSolid);
		}
		break;

	case 2:

#pragma region"クリア時（シーン終了処理）"

		if (isStartChange_ || isEndChange_) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CColor_, kFillModeSolid);
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CtoGColor_, kFillModeSolid);
		}



#pragma endregion

		break;

	case 3:
#pragma region"シーン開始処理"
		if (isStartChange_ || isEndChange_) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CColor_, kFillModeSolid);
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CtoGColor_, kFillModeSolid);
		}
#pragma endregion

#pragma region"シーン終了処理"
		if (isStartChange_ || isEndChange_) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CColor_, kFillModeSolid);
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, CtoGColor_, kFillModeSolid);
		}
#pragma endregion
		break;
	default:
		break;
	}

}