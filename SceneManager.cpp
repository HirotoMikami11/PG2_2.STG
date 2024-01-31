#include "SceneManager.h"

SceneManager::SceneManager() {
	title = new Title;
	game = new Game;
	clear = new GameClear;
	over = new GameOver;
}

SceneManager::~SceneManager() {
	delete title;
	delete game;
	delete clear;
	delete over;
}
void SceneManager::Update(char* keys, char* preKeys) {
	keys; preKeys;
	switch (Scene::SceneNum_) {

	case TITLE:
		title->Update(keys, preKeys);
		break;

	case GAME:
		game->Update(keys, preKeys);
		break;
	case CLEAR:
		clear->Update(keys, preKeys);
		break;
	case OVER:
		over->Update(keys, preKeys);
		break;
	default:
		break;
	}

	//ここにシーンチェンジの関数を設置する

}
void SceneManager::Draw(Resources rs) {
	rs;
	switch (Scene::SceneNum_) {

	case TITLE:
		title->Draw(rs);
		break;

	case GAME:
		game->Draw(rs);
		break;
	case CLEAR:
		clear->Draw(rs);
		break;
	case OVER:
		over->Draw(rs);
		break;
	default:
		break;
	}
	//ここにシーンチェンジの関数を設置する
}