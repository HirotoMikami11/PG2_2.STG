#include "PlayerBullet.h"


PlayerBullet::PlayerBullet() {
	pos_ = { -640,-200 };
	size_ = { 10,10 };
	speed_ = 15;
	isShot_ = false;
}
PlayerBullet::~PlayerBullet() {

}
void PlayerBullet::Update() {

	if (isShot_) {
		pos_.y += speed_;

		if (pos_.y + size_.y >= 720) {//画面上に行ったら弾丸が消えるようにする
			isShot_ = false;
		}

	} else {
		//発射されていないときは画面外に置いておく
		pos_ = { -640,-200 };
	}


}


void PlayerBullet::SetBullet(Vector2 playerPos_) {
	pos_ = playerPos_;
	isShot_ = true;
}

void PlayerBullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x),
			static_cast<int>((pos_.y - 720) * -1),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, 0x6666FFFF, kFillModeSolid);
	}
}
