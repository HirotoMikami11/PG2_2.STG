#pragma once
#include"Object.h"

class EnemyBullet :public Object {

	bool isShot_;
	bool preIsShot_;
	//ホーミングする処理の関数
	bool isHoming_;
	float toPlayerLength_;
	Vector2 dir_;
	Vector2 normalizedir_;

	int reflectCount_;
	const int kmaxReflectCount_=3;

public:
	EnemyBullet();//コンストラクタ
	~EnemyBullet();//デストラクタ
	void Update(Vector2 PlayerPos_);
	void Draw();
	void SetBullet(Vector2 EnemyPos_);
	void PreShotUpdate();

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetisShot() { return isShot_; };
	bool GetpreIsShot() { return preIsShot_; };

};