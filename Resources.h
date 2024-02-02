#pragma once
#include"Novice.h"
class Resources{

public:

	int whiteGH_ = Novice::LoadTexture("white1x1.png");
	int GameTitleGH_= Novice::LoadTexture("./Resources/hanerushot.png");
	int PressSpaceGH_= Novice::LoadTexture("./Resources/pressspace.png");
	int GameOverGH_ = Novice::LoadTexture("./Resources/gameover.png");
	int GameClearGH_ = Novice::LoadTexture("./Resources/gameclear.png");
	int ToTitleSpaceGH_ = Novice::LoadTexture("./Resources/totitlespace.png");
	int HpGH_= Novice::LoadTexture("./Resources/hp.png");
};

