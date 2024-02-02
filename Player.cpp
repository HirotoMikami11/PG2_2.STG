#include "Player.h"

const int Player::kMaxPBullet = 10;

Player::Player() {//コンストラクタ
	pos_ = { 640,200 };
	size_ = { 20,20 };
	move_ = { 0,0 };
	speed_ = 5;
	isAlive_ = true;

	for (int i = 0; i < kMaxPBullet; i++) {
		Bullet[i] = new PlayerBullet;
	}
	shotTimer_ = kMaxShotTimer_;
	canShot_ = true;
	HP_ = 5;
	isDamage_ = false;
	respownTimer_ = kMaxRespownTimer_;
	isDraw_ = true;

	for (int i = 0; i < HP_; i++) {
		hpBox[i] = new Box({ 0,0 }, { 48,48 }, BLUE);//あと何回倒せばいいのかを表示するボックス
		hpBox[i]->SetPos({ 100, 100 + (size_.y * 3.0f * (i + 1)) });
	}


}

Player::~Player() {//デストラクタ
	for (int i = 0; i < kMaxPBullet; i++) {
		delete Bullet[i];
	}
	for (int i = 0; i < HP_; i++) {
		delete hpBox[i];
	}
}

void Player::Reset() {
	pos_ = { 640,200 };
	size_ = { 20,20 };
	move_ = { 0,0 };
	speed_ = 5;
	isAlive_ = true;

	for (int i = 0; i < kMaxPBullet; i++) {
		Bullet[i]->Reset();
	}
	shotTimer_ = kMaxShotTimer_;
	canShot_ = true;
	HP_ = 5;
	isDamage_ = false;
	respownTimer_ = kMaxRespownTimer_;
	isDraw_ = true;
}
//更新
void Player::Update(char* keys, char* preKeys) {


	/*----------------------------------------------------------------------*/

							//移動関係の処理//

	/*----------------------------------------------------------------------*/

	if (keys[DIK_A]) {
		move_.x = -1;
	}

	if (keys[DIK_D]) {
		move_.x = 1;
	}

	if (keys[DIK_W]) {
		move_.y = 1;
	}
	if (keys[DIK_S]) {
		move_.y = -1;
	}

	pos_.x += move_.x * speed_;
	pos_.y += move_.y * speed_;

	move_ = { 0,0 };

	if (pos_.x <= WindowSize::kOutSize_.x + size_.x) {
		pos_.x = WindowSize::kOutSize_.x + size_.x;
	}
	if (pos_.x >= (1280 - WindowSize::kOutSize_.x) - size_.x) {
		pos_.x = (1280 - WindowSize::kOutSize_.x) - size_.x;
	}

	if (pos_.y <= 0 + size_.y) {
		pos_.y = 0 + size_.x;
	}
	if (pos_.y >= 720 - size_.y) {
		pos_.y = 720 - size_.x;
	}


	/*----------------------------------------------------------------------*/

							//弾丸を発射する関係の処理//

	/*----------------------------------------------------------------------*/
	//弾を打てない状態の時
	if (!canShot_) {
		shotTimer_--;//タイマーを減らし
		if (shotTimer_ == 0) {//０になったら打てるようにする
			canShot_ = true;
			shotTimer_ = kMaxShotTimer_;
		}
	}

	//弾を発射する処理
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
		if (canShot_ == true) {

			canShot_ = false;

			for (int i = 0; i < kMaxPBullet; i++) {
				if (!Bullet[i]->GetisShot()) {//弾が発射されていなければ
					Bullet[i]->SetBullet(pos_);//自機の座標に弾を持ってくる
					break;
				}

			}

		}
	}

	//弾丸の更新
	for (int i = 0; i < kMaxPBullet; i++) {
		Bullet[i]->Update();
	}
	/*----------------------------------------------------------------------*/

					//弾丸を発射する関係の処理ここまで//

	/*----------------------------------------------------------------------*/

	if (isDamage_) {

		if (respownTimer_ % 10 == 0) {//点滅
			if (isDraw_) {
				isDraw_ = false;
			} else {
				isDraw_ = true;
			}
		}
		respownTimer_--;
		if (respownTimer_ == 0) {//タイマー０になったら無敵時間終わり
			isDamage_ = false;
			respownTimer_ = kMaxRespownTimer_;//タイマーリセット
		}
	}





	if (HP_ <= 0) {
		isAlive_ = false;
	}
	if (!isAlive_) {
		isDraw_ = false;
	}

}

//当たり判定
void Player::OnColision() {
	if (!isDamage_) {//ダメージを受けていないとき
		isDamage_ = true;
		HP_--;
	}
}
void Player::BulleOnColision(int element) {
	Bullet[element]->SetIsShot();

}

//描画
void Player::Draw(Resources rs) {


	for (int i = 0; i < kMaxPBullet; i++) {
		Bullet[i]->Draw();
	}

	if (isDraw_) {//自機が生きている間だけ描画
		Novice::DrawEllipse(static_cast<int>(pos_.x),
			static_cast<int>((pos_.y - 720) * -1),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, BLUE, kFillModeSolid);
	}
	for (int i = 0; i < HP_; i++) {
		hpBox[i]->MyDrawSprite(rs.HpGH_);
	}




}

