#pragma once
#include "Scene.h"

class Title{
public:

	Title();
	~Title();
	void Update(char* keys, char* preKeys);
	void Draw(Resources rs);
};

