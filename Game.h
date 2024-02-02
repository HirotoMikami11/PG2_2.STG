#pragma once
#include "SceneChange.h"
#include "Player.h"
#include "Enemy.h"

class Game {
	const int kMaxEnemy = 3;

	Player* player;
	Enemy* enemy[3];

public:

	Game();
	~Game();
	void Reset();
	void Update(char* keys, char* preKeys,SceneChange *SC);
	void Colisions();
	void Draw(Resources rs);

};

