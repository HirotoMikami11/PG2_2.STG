#include "Bullet.h"
Bullet::Bullet() {
	pos_ = { -640,-200 };
	size_ = { 10,10 };
	speed_ = 3;

	isShot_ = false;
	preIsShot_ = false;


	dir_ = { 0,0 };


	reflectCount_ = kmaxReflectCount_;

}
Bullet::~Bullet() {

}
void Bullet::Reset() {
	pos_ = { -640,-200 };
	size_ = { 10,10 };
	speed_ = 3;

	isShot_ = false;
	preIsShot_ = false;


	dir_ = { 0,0 };
	reflectCount_ = kmaxReflectCount_;
}
void Bullet::Update() {
	/*----------------------------------------------------------------------*/
						//発射された弾丸の処理//
	/*----------------------------------------------------------------------*/
	if (isShot_) {
		pos_.x += dir_.x * speed_;
		pos_.y += dir_.y * speed_;
		//反射する処理
		if (reflectCount_ > 0) {
			if (pos_.y <= 0.0f + size_.y ||
				pos_.y >= 720.0f - size_.y) {
				dir_.y *= -1;
				speed_ *= 1.5f;
				reflectCount_--;
			}

			if (pos_.x <= WindowSize::kOutSize_.x + size_.x ||
				pos_.x >= (1280.0f - WindowSize::kOutSize_.x) - size_.x) {
				dir_.x *= -1;
				speed_ *= 1.5f;
				reflectCount_--;
			}
		} else {

			//画面上に行ったら弾丸消える
			if (pos_.y <= 0.0f - size_.y ||
				pos_.y >= 720.0f + size_.y ||
				pos_.x <= WindowSize::kOutSize_.x - size_.x ||
				pos_.x >= (1280.0f - WindowSize::kOutSize_.x) + size_.x) {

				isShot_ = false;
			}
		}

	} else {//撃たれていないときは画面外へ
		pos_ = { -640,-200 };
	}


}

void Bullet::PreShotUpdate() {
	preIsShot_ = isShot_;

}

void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x),
			static_cast<int>((pos_.y - 720) * -1),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, 0x000000FF, kFillModeSolid);
	}

}

void Bullet::OnColision() {
	isShot_ = false;
	pos_ = { -640,-200 };
}

void Bullet::SetBulletEnemy(Vector2 EnemyPos_, Vector2 PlayerPos_) {
	pos_ = EnemyPos_;


	//自機の方向に弾丸を飛ばす
	dir_.x = -cosf(atan2f(pos_.y - PlayerPos_.y, pos_.x - PlayerPos_.x));
	dir_.y = -sinf(atan2f(pos_.y - PlayerPos_.y, pos_.x - PlayerPos_.x));
	speed_ = 3;

	isShot_ = true;
	reflectCount_ = kmaxReflectCount_;
}

void Bullet::SetBulletPlayer(Vector2 playerPos_) {
	pos_ = playerPos_;
	dir_.x = 0;
	dir_.y = 1;
	speed_ = 10;
	isShot_ = true;
	reflectCount_ = kmaxReflectCount_;
}