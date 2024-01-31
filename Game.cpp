#include "Game.h"
Game::Game() {
	player = new Player;
	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i] = new Enemy({ 640,400.0f+ 100.0f * i }, powf(-1, float(i)));
	}
}
Game::~Game() {
	delete player;
	for (int i = 0; i < kMaxEnemy; i++) {
		delete enemy[i];
	}
}
void Game::Update(char* keys, char* preKeys) {

	player->Update(keys, preKeys);

	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i]->Update(player->GetPos());
	}

}
void Game::Draw(Resources rs) {
	rs;

	player->Draw();	
	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i]->Draw();
	}
	
	Novice::DrawBox(0, 0, WindowSize::kOutSize_.x, 720, 0.0f, 0x000000FF, kFillModeSolid);
	Novice::DrawBox(1280, 0, -WindowSize::kOutSize_.x, 720, 0.0f, 0x000000FF, kFillModeSolid);
	
	
}
