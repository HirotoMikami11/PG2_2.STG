#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

class Game {
	const int kMaxEnemy = 3;

	Player* player;
	Enemy* enemy[3];

public:

	Game();
	~Game();
	void Update(char* keys, char* preKeys);
	void Draw(Resources rs);

};

