#include "SceneManager.h"

SceneManager::SceneManager() {
	title = new Title;
	game = new Game;
	clear = new GameClear;
	over = new GameOver;
	SC = new SceneChange();
}

SceneManager::~SceneManager() {
	delete title;
	delete game;
	delete clear;
	delete over;
	delete SC;

}
void SceneManager::Update(char* keys, char* preKeys) {

	switch (Scene::SceneNum_) {

	case TITLE:
		title->Update(keys, preKeys, SC);
		game->Reset();

		break;
	case GAME:
		game->Update(keys, preKeys, SC);
		break;
	case CLEAR:
		clear->Update(keys, preKeys, SC);
		break;
	case OVER:
		over->Update(keys, preKeys, SC);
		break;
	default:
		break;
	}
	SC->Update();
	//ここにシーンチェンジの関数を設置する


}
void SceneManager::Draw(Resources rs) {

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
	SC->Draw();
	//ここにシーンチェンジの関数を設置する
}