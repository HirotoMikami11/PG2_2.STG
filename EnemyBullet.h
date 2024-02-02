#pragma once
#include"Object.h"

class EnemyBullet :public Object {

	bool isShot_;
	bool preIsShot_;
	//ホーミングする処理の関数
	bool isHoming_;

	Vector2 dir_;
	Vector2 normalizedir_;

	int reflectCount_;
	const int kmaxReflectCount_=3;

public:
	float toPlayerLength_;

	EnemyBullet();//コンストラクタ
	~EnemyBullet();//デストラクタ
	void Reset();
	void Update(Vector2 PlayerPos_);
	void Draw();
	void SetBullet(Vector2 EnemyPos_, Vector2 PlayerPos_);
	void PreShotUpdate();
	void OnColision();

	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetisShot() { return isShot_; };
	bool GetpreIsShot() { return preIsShot_; };
	void SetIsShot() {  isShot_=false; };

};