#pragma once
#include"Vector2.h"
#include"Novice.h"
#include"Resources.h"

class Box {

	Vector2 pos_;
	Vector2 size_;
	unsigned int color_;
	int Timer_;
public:

	Box(Vector2 pos,Vector2 size,unsigned int color);
	~Box();
	void MyDrawSprite(int rs);
	void MyDrawSpriteBlinking(int rs);
	void MyDrawSpriteWhite(Resources rs);
	void SetPos(Vector2 pos) { pos_ = pos; };
	
};

