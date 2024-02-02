#pragma once
#include "SceneChange.h"

class Title{

	Box* pressStart;
	Box* titleName;

public:

	Title();
	~Title();
	void Update(char* keys, char* preKeys,SceneChange *SC);
	void Draw(Resources rs);
};

