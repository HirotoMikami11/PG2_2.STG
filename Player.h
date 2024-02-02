#pragma once
#include "Object.h"
#include "Bullet.h"

class Player :public Object {

	Vector2 move_;

	bool isAlive_;
	bool isDraw_;

	static const int kMaxPBullet;
	Bullet* bullet[20];
	int shotTimer_;
	const int kMaxShotTimer_ = 10;
	bool canShot_;

	int HP_;
	int isDamage_;
	int respownTimer_;
	const int kMaxRespownTimer_ = 120;

	Box* hpBox[5];//あと何回倒せばいいのかを表示するボックス

public:

	Player();//コンストラクタ
	~Player();//デストラクタ

	void Reset();
	//更新
	void Update(char* keys, char* preKeys);
	void OnColision();
	void BulleOnColision(int element);
	
	//描画
	void Draw(Resources rs);

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetDamage() { return isDamage_; };
	bool GetAlive() { return isAlive_; };
	Vector2 GetBulletPos(int element) { return bullet[element]->GetPos(); };
	Vector2 GetBulleSize(int element) { return bullet[element]->GetSize(); };
	void SetBulleShot(int element) { return bullet[element]->SetIsShot(); };
};

