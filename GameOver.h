#pragma once

#include "SceneChange.h"
class GameOver{
	Box* gameoverFont;
	Box* pressSpace;
public:

	GameOver();
	~GameOver();
	void Update(char* keys, char* preKeys,SceneChange *SC);
	void Draw(Resources rs);
};

