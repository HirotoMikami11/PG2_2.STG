#pragma once
#include "Object.h"
#include "PlayerBullet.h"

class Player :public Object {

	Vector2 move_;

	bool isAlive_;
	bool isDraw_;

	static const int kMaxPBullet;
	PlayerBullet* Bullet[10];
	int shotTimer_;
	const int kMaxShotTimer_ = 10;
	bool canShot_;

	int HP_;
	int isDamage_;
	int respownTimer_;
	const int kMaxRespownTimer_ = 120;

public:

	Player();//コンストラクタ
	~Player();//デストラクタ

	//更新
	void Update(char* keys, char* preKeys);
	void OnColision();
	void BulleOnColision(int element);
	
	//描画
	void Draw();

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetDamage() { return isDamage_; };
	Vector2 GetBulletPos(int element) { return Bullet[element]->GetPos(); };
	Vector2 GetBulleSize(int element) { return Bullet[element]->GetSize(); };
	void SetBulleShot(int element) { return Bullet[element]->SetIsShot(); };
};

