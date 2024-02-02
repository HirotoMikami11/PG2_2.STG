#include "Game.h"
Game::Game() {
	player = new Player;
	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i] = new Enemy({ 640,400.0f + 100.0f * i }, powf(-1, float(i)));
	}
}

Game::~Game() {
	delete player;
	for (int i = 0; i < kMaxEnemy; i++) {
		delete enemy[i];
	}
}

void Game::Reset() {
	player->Reset();
	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i]->Reset({ 640,400.0f + 100.0f * i }, powf(-1, float(i)));
	}
}

void Game::Update(char* keys, char* preKeys, SceneChange* SC) {


	player->Update(keys, preKeys);

	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i]->Update(player->GetPos());
	}

	Colisions();

	if (!SC->GetStartChange() && !SC->GetEndChange()) {
		if (Enemy::enemyKillCount_ <= 0) {
			SC->SetGameClear();
			SC->SetEndChange();
		}
	}

	if (!SC->GetStartChange() && !SC->GetEndChange()) {
		if (!player->GetAlive()) {
			SC->SetGameOver();
			SC->SetEndChange();
		}
	}
}


void Game::Colisions() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 20; j++) {
			if (enemy[i]->GetAlive()) {
				if (Colision(enemy[i]->GetPos(), player->GetBulletPos(j), enemy[i]->GetSize(), player->GetBulleSize(j))) {
					enemy[i]->OnColision();
					player->BulleOnColision(j);
				}
			}

		}
		for (int j = 0; j < 3; j++) {
			if (!player->GetDamage()) {
				if (Colision(player->GetPos(), enemy[i]->GetBulletPos(j),
					player->GetSize(), enemy[i]->GetBulleSize(j))) {

					player->OnColision();;
					enemy[i]->BulletOnColision(j);
				}
			}
		}
	}

}

void Game::Draw(Resources rs) {
	Novice::DrawBox(0, 0, WindowSize::kOutSize_.x, 720, 0.0f, 0x000000FF, kFillModeSolid);
	Novice::DrawBox(1280, 0, -WindowSize::kOutSize_.x, 720, 0.0f, 0x000000FF, kFillModeSolid);

	player->Draw(rs);
	for (int i = 0; i < kMaxEnemy; i++) {
		enemy[i]->Draw(rs);
	}


}
