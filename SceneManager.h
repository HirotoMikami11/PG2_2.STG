#pragma once
#include"Title.h"
#include"Game.h"
#include"GameClear.h"
#include"GameOver.h"


class SceneManager{
	Title* title;
	Game* game;
	GameClear* clear;
	GameOver* over;

public:
	SceneManager();
	~SceneManager();

	void Update(char* keys,char* preKeys);
	void Draw(Resources rs);

};

