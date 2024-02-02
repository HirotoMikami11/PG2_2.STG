#include "Enemy.h"

const int Enemy::kMaxEBullet = 3;
const int Enemy::kMaxEnemyKillCount_ = 5;
int Enemy::enemyKillCount_ = Enemy::kMaxEnemyKillCount_;

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
	canShot_ = false;

	reloadTimer_ = kMaxReloadTimer_;
	isReload_ = true;
	respawnTimer_ = kMaxRespawnTimer_;
	for (int i = 0; i < kMaxEnemyKillCount_; i++) {
		hpBox[i] = new Box({ 0,0 }, { 48,48 }, RED);//あと何回倒せばいいのかを表示するボックス
		hpBox[i]->SetPos({ 1120, 150 + (size_.y * 3.0f * (i + 1)) });
	}
}

Enemy::~Enemy() {//デストラクタ
	for (int i = 0; i < kMaxEBullet; i++) {
		delete Bullet[i];
	}
	for (int i = 0; i < kMaxEnemyKillCount_; i++) {
		delete hpBox[i];
	}
}

void Enemy::Reset(Vector2 pos, float moveX) {
	pos_ = pos;
	size_ = { 20,20 };
	move_ = { moveX,0 };
	speed_ = 5;
	isAlive_ = true;
	shotCount_ = kMaxShoitCount_;
	for (int i = 0; i < kMaxEBullet; i++) {
		Bullet[i]->Reset();
	}
	shotTimer_ = kMaxShotTimer_;
	canShot_ = false;

	reloadTimer_ = kMaxReloadTimer_;
	isReload_ = true;
	respawnTimer_ = kMaxRespawnTimer_;
	enemyKillCount_ = kMaxEnemyKillCount_;
}

//更新
void Enemy::Update(Vector2 PlayerPos) {



	/*----------------------------------------------------------------------*/

							//移動関係の処理//

	/*----------------------------------------------------------------------*/
	if (isAlive_) {
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
			if (isAlive_) {
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
							Bullet[i]->SetBullet(pos_, PlayerPos);//自機の座標に弾を持ってくる
							shotCount_--;//発射するたびにカウントを減らす
							break;
						}

					}
				}
			}

			if (shotCount_ == 0) {//カウントが０の時（全ての弾丸が発射されているとき）
				isReload_ = true;//リロード状態にする
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

	}



	//弾丸の更新
	for (int i = 0; i < kMaxEBullet; i++) {
		//前フレーム弾丸が発射されている状態だったかどうか判断する
		Bullet[i]->PreShotUpdate();
		Bullet[i]->Update(PlayerPos);
		if (!Bullet[i]->GetisShot() &&
			Bullet[i]->GetpreIsShot()) {
			shotCount_++;
		}



	}




	/*----------------------------------------------------------------------*/

								//リスポーンの処理//

	/*----------------------------------------------------------------------*/

	if (!isAlive_) {
		respawnTimer_--;
		if (respawnTimer_ <= 0) {
			isAlive_ = true;
			respawnTimer_ = kMaxRespawnTimer_;
		}
	}

}

//当たり判定
void Enemy::OnColision() {
	isAlive_ = false;
	enemyKillCount_--;
}

void Enemy::BulletOnColision(int element) {
	Bullet[element]->SetIsShot();
	shotCount_++;
}
//描画
void Enemy::Draw(Resources rs) {


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

	for (int i = 0; i < Enemy::enemyKillCount_; i++) {
		hpBox[i]->MyDrawSprite(rs.HpGH_);
	}


}

