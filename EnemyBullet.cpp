#include "EnemyBullet.h"
EnemyBullet::EnemyBullet() {
	pos_ = { -640,-200 };
	size_ = { 5,5 };
	speed_ = 2;

	isShot_ = false;
	preIsShot_ = false;
	//ホーミングする処理の関数
	isHoming_ = false;
	toPlayerLength_ = 0;
	dir_ = { 0,0 };
	normalizedir_ = { 0,0 };

	reflectCount_ = kmaxReflectCount_;

}
EnemyBullet::~EnemyBullet() {

}
void EnemyBullet::Update(Vector2 PlayerPos_) {
	/*----------------------------------------------------------------------*/
						//発射された弾丸の処理//
	/*----------------------------------------------------------------------*/
	if (isShot_) {
		if (isHoming_) {
			if (toPlayerLength_ >= 100) {
				//一定距離以上ならば弾丸が誘導する
				dir_.x = PlayerPos_.x - pos_.x;
				dir_.y = PlayerPos_.y - pos_.y;
				toPlayerLength_ = sqrtf(dir_.x * dir_.x + dir_.y * dir_.y);
				normalizedir_ = dir_;
			} else {//一定距離以内になったとき、誘導を外す
				isHoming_ = false;
			}
		}

		//ベクトルを正規化
		if (toPlayerLength_ != 0.0f) {
			normalizedir_.x = dir_.x / toPlayerLength_;
			normalizedir_.y = dir_.x / toPlayerLength_;
		}

		//弾の移動処理
		pos_.x += normalizedir_.x + speed_;
		pos_.y += normalizedir_.y + speed_;

		//反射する処理
		if (reflectCount_ > 0) {
			if (pos_.y <= 0.0f + size_.y ||
				pos_.y >= 720.0f - size_.y) {
				dir_.y *= -1;
				reflectCount_--;
			}

			if (pos_.x <= WindowSize::kOutSize_.x + size_.x ||
				pos_.x >= (1280.0f - WindowSize::kOutSize_.x) - size_.x) {
				dir_.x *= -1;
				reflectCount_--;
			}
		}

		//画面上に行ったら弾丸消える
		if (pos_.y <= 0.0f - size_.y ||
			pos_.y >= 720.0f + size_.y ||
			pos_.x <= WindowSize::kOutSize_.x + size_.x ||
			pos_.x >= (1280.0f - WindowSize::kOutSize_.x) - size_.x) {
			isShot_ = false;
		}

	} else {//撃たれていないときは画面外へ
		pos_ = { -640,-200 };

	}
}

void EnemyBullet::PreShotUpdate() {
	preIsShot_ = isShot_;
}

void EnemyBullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x),
			static_cast<int>((pos_.y - 720) * -1),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, 0x000000FF, kFillModeSolid);
	}
}
void EnemyBullet::SetBullet(Vector2 EnemyPos_) {
	pos_ = EnemyPos_;
	isShot_ = true;
	reflectCount_ = kmaxReflectCount_;
}