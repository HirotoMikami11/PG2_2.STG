#include "EnemyBullet.h"
EnemyBullet::EnemyBullet() {
	pos_ = { -640,-200 };
	size_ = { 10,10 };
	speed_ = 3;

	isShot_ = false;
	preIsShot_ = false;
	//ホーミングする処理の関数
	isHoming_ = true;
	toPlayerLength_ = 1000.0f;
	dir_ = { 0,0 };
	normalizedir_ = { 0,0 };

	reflectCount_ = kmaxReflectCount_;

}
EnemyBullet::~EnemyBullet() {

}
void EnemyBullet::Reset() {
	pos_ = { -640,-200 };
	size_ = { 10,10 };
	speed_ = 3;

	isShot_ = false;
	preIsShot_ = false;
	//ホーミングする処理の関数
	isHoming_ = true;
	toPlayerLength_ = 1000.0f;
	dir_ = { 0,0 };
	normalizedir_ = { 0,0 };

	reflectCount_ = kmaxReflectCount_;
}
void EnemyBullet::Update(Vector2 PlayerPos_) {
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
	PlayerPos_;
#pragma region"没"
	/*
	if (isShot_) {
		if (isHoming_) {
			if (toPlayerLength_ >= 100.0f) {
				//一定距離以上ならば弾丸が誘導する
				dir_.x = PlayerPos_.x - pos_.x;
				dir_.y = PlayerPos_.y - pos_.y;
				toPlayerLength_ = sqrtf(dir_.x * dir_.x + dir_.y * dir_.y);
				normalizedir_.x = dir_.x;
				normalizedir_.y = dir_.y;
			} 
			
			if(toPlayerLength_ < 100.0f){//一定距離以内になったとき、誘導を外す
				isHoming_ = false;
			}
		}

		if (toPlayerLength_ != 0.0f) {
			normalizedir_.x = dir_.x / toPlayerLength_;
			normalizedir_.y = dir_.x / toPlayerLength_;
		}

		//弾の移動処理
		pos_.x += normalizedir_.x * speed_;
		pos_.y += normalizedir_.y * speed_;

		//反射する処理
		/*
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
		*/
/*
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
*/
#pragma endregion

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

void EnemyBullet::OnColision() {
	isShot_ = false;
	pos_ = { -640,-200 };
}

void EnemyBullet::SetBullet(Vector2 EnemyPos_, Vector2 PlayerPos_) {
	pos_ = EnemyPos_;


	//自機の方向に弾丸を飛ばす
	dir_.x = -cosf(atan2f(pos_.y - PlayerPos_.y, pos_.x - PlayerPos_.x));
	dir_.y = -sinf(atan2f(pos_.y - PlayerPos_.y, pos_.x - PlayerPos_.x));
	speed_ = 3;

	isShot_ = true;
	isHoming_ = true;
	toPlayerLength_ = 1000.0f;
	reflectCount_ = kmaxReflectCount_;
}