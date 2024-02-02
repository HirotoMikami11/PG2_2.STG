
#pragma once
#include"Object.h"

class Bullet :public Object {

	bool isShot_;
	bool preIsShot_;
	//ホーミングする処理の関数
	Vector2 dir_;


	int reflectCount_;
	const int kmaxReflectCount_ = 3;

public:


	Bullet();//コンストラクタ
	~Bullet();//デストラクタ
	void Reset();
	void Update();
	void Draw();
	void SetBulletEnemy(Vector2 EnemyPos_, Vector2 PlayerPos_);
	void SetBulletPlayer(Vector2 playerPos_);
	void PreShotUpdate();
	void OnColision();

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetisShot() { return isShot_; };
	bool GetpreIsShot() { return preIsShot_; };
	void SetIsShot() { isShot_ = false; };

};