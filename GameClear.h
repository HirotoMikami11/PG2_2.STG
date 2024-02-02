#pragma once

#include "SceneChange.h"
class GameClear{
	Box* gameclearFont;
	Box* pressSpace;
public:
	GameClear();
	~GameClear();
	void Update(char* keys, char* preKeys, SceneChange* SC);
	void Draw(Resources rs);
};

