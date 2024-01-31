﻿#include "Enemy.h"

const int Enemy::kMaxEBullet = 3;

Enemy::Enemy(Vector2 pos, float moveX) {//コンストラクタ
	pos_ = pos;
	size_ = { 20,20 };
	move_ = { moveX,0 };
	speed_ = 5;
	isAlive_ = true;
	shotCount_ = kMaxShoitCount_;
	for (int i = 0; i < kMaxEBullet; i++) {
		Bullet[i] = new EnemyBullet;
	}
	shotTimer_ = kMaxShotTimer_;
	canShot_ = true;

	reloadTimer_ = kMaxReloadTimer_;
	isReload_ = false;
}

Enemy::~Enemy() {//デストラクタ
	for (int i = 0; i < kMaxEBullet; i++) {
		delete Bullet[i];
	}
}


//更新
void Enemy::Update(Vector2 PlayerPos) {
	
	//前フレーム弾丸が発射されている状態だったかどうか判断する
	for (int i = 0; i < kMaxEBullet; i++) {
		Bullet[i]->PreShotUpdate();
	}

	/*----------------------------------------------------------------------*/

							//移動関係の処理//

	/*----------------------------------------------------------------------*/

	//移動処理
	pos_.x += move_.x * speed_;
	pos_.y += move_.y * speed_;

	//画面端で方向転換する
	if (pos_.x <= WindowSize::kOutSize_.x + size_.x) {
		pos_.x = WindowSize::kOutSize_.x + size_.x;
		move_.x *= -1;
	}
	if (pos_.x >= (1280 - WindowSize::kOutSize_.x) - size_.x) {
		pos_.x = (1280 - WindowSize::kOutSize_.x) - size_.x;
		move_.x *= -1;
	}



	/*----------------------------------------------------------------------*/

							//弾丸を発射する関係の処理//

	/*----------------------------------------------------------------------*/


	//弾を発射する処理
	if (!isReload_) {
		//弾を打てない状態の時
		if (!canShot_) {
			shotTimer_--;//タイマーを減らし
			if (shotTimer_ == 0) {//０になったら打てるようにする
				canShot_ = true;
				shotTimer_ = kMaxShotTimer_;
			}
		}
		if (canShot_) {
			canShot_ = false;
			for (int i = 0; i < kMaxEBullet; i++) {
				if (!Bullet[i]->GetisShot()) {//弾が発射されていなければ
					Bullet[i]->SetBullet(pos_);//自機の座標に弾を持ってくる
					shotCount_--;//発射するたびにカウントを減らす
					break;
				}

			}
		}
	} else {//Reload_がtureのとき
		if (shotCount_ == 3) {//カウントが３のとき（一発も発射されていないとき）
			reloadTimer_--;//タイマーを減らし
			if (reloadTimer_ == 0) {//０になったら打てるようにする
				isReload_ = false;
				reloadTimer_ = kMaxReloadTimer_;
			}
		}

	}

	if (shotCount_ == 0) {//カウントが０の時（全ての弾丸が発射されているとき）
		isReload_ = true;//リロード状態にする
	}


	//弾丸の更新
	for (int i = 0; i < kMaxEBullet; i++) {
		Bullet[i]->Update(PlayerPos);
		if (Bullet[i]->GetisShot()!= Bullet[i]->GetpreIsShot()) {
			shotCount_++;
		}
	}




	/*----------------------------------------------------------------------*/

					//弾丸を発射する関係の処理②②まで//

	/*----------------------------------------------------------------------*/

}

//当たり判定
void Enemy::Colision() {
	//自機と敵の弾
	//自機が死ぬ


	//自機と敵
	//自機が死ぬ

}

//描画
void Enemy::Draw() {


	for (int i = 0; i < kMaxEBullet; i++) {
		Bullet[i]->Draw();
	}

	if (isAlive_) {//敵が生きている間だけ描画
		Novice::DrawEllipse(static_cast<int>(pos_.x),
			static_cast<int>((pos_.y - 720) * -1),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, RED, kFillModeSolid);
	}



}
