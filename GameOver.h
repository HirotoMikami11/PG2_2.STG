#pragma once

#include "Scene.h"
class GameOver{
public:

	GameOver();
	~GameOver();
	void Update(char* keys, char* preKeys);
	void Draw(Resources rs);
};

