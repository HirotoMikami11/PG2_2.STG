#pragma once
#include"Title.h"
#include"Game.h"
#include"GameClear.h"
#include"GameOver.h"
#include"SceneChange.h"


class SceneManager{
	Title* title;
	Game* game;
	GameClear* clear;
	GameOver* over;
	SceneChange* SC;

public:
	SceneManager();
	~SceneManager();

	void Update(char* keys,char* preKeys);
	void Draw(Resources rs);

};

