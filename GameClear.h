#pragma once

#include "Scene.h"
class GameClear{
public:
	GameClear();
	~GameClear();
	void Update(char* keys, char* preKeys);
	void Draw(Resources rs);
};

