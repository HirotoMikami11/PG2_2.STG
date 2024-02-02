#include "GameOver.h"
GameOver::GameOver() {
	pressSpace = new Box({ 640,600 }, { 600,120 },WHITE);
	gameoverFont = new Box({ 640,200 }, { 880,200 }, WHITE);


}
GameOver::~GameOver() {
	delete pressSpace;
	delete gameoverFont;
}
void GameOver::Update(char* keys, char* preKeys, SceneChange* SC) {
	if (!SC->GetStartChange() && !SC->GetEndChange()) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			SC->SetEndChange();
		}
	}
}
void GameOver::Draw(Resources rs) {

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	pressSpace->MyDrawSpriteBlinking(rs.ToTitleSpaceGH_);

	gameoverFont->MyDrawSprite(rs.GameOverGH_);

}