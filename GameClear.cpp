#include "GameClear.h"
GameClear::GameClear() {
	pressSpace = new Box({ 640,600 }, { 600,120 }, WHITE);
	gameclearFont = new Box({ 640,200 }, { 880,200 }, WHITE);
}
GameClear::~GameClear() {
	delete pressSpace;
	delete gameclearFont;

}
void GameClear::Update(char* keys, char* preKeys, SceneChange* SC) {
	if (!SC->GetStartChange() && !SC->GetEndChange()) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			SC->SetEndChange();
		}
	}
}
void GameClear::Draw(Resources rs) {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	pressSpace->MyDrawSpriteBlinking(rs.ToTitleSpaceGH_);

	gameclearFont->MyDrawSprite(rs.GameClearGH_);
}