#pragma once
#include "Object.h"
#include "EnemyBullet.h"
class Enemy :public Object{

	Vector2 move_;
	bool isAlive_;						//生きているか否か

	static const int kMaxEBullet;		//弾丸の最大数
	EnemyBullet* Bullet[3];
	int shotTimer_;						//連射するときに使用するタイマー
	const int kMaxShotTimer_ = 30;		//最大値
	bool canShot_;						//連射できるかどうか
	int shotCount_;						//発射した弾丸の数をカウントする変数
	const int kMaxShoitCount_ = 3;
	int reloadTimer_;					//３発発射してから、もう一度３発発射するまでの時間
	const int kMaxReloadTimer_ = 180;	//最大値
	bool isReload_;						//リロード中か否かfalseのときに発射する
	
	int respawnTimer_;					//リスポーンまでのタイマー
	const int kMaxRespawnTimer_ = 120;	//最大値

public:

	Enemy(Vector2 pos,float moveX);//コンストラクタ
	~Enemy();//デストラクタ

	//更新
	void Update(Vector2 PlayerPos);
	void OnColision();
	void BulletOnColision(int element);

	//描画
	void Draw();

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	bool  GetAlive () { return isAlive_; };
	Vector2 GetSize() { return size_; };
	Vector2 GetBulletPos(int element) { return Bullet[element]->GetPos(); };
	Vector2 GetBulleSize(int element) { return Bullet[element]->GetSize(); };
	void SetBulleShot(int element) { return Bullet[element]->SetIsShot(); };
};

