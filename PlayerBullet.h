#pragma once
#include"Object.h"

class PlayerBullet :public Object{

	bool isShot_;
public:
	PlayerBullet();//コンストラクタ
	~PlayerBullet();//デストラクタ
	void Update();
	void Draw();
	void SetBullet(Vector2 playerPos_);


	//アクセッサ類
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	bool GetisShot() { return isShot_; };

};

