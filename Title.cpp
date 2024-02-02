#include "Title.h"
Title::Title() {

	pressStart = new Box({ 640,600 }, { 550,120 }, WHITE);
	titleName = new Box({ 640,200 }, { 880,200 }, WHITE);



}

Title::~Title() {
	delete pressStart;
	delete titleName;

}

void Title::Update(char* keys, char* preKeys, SceneChange* SC) {
	if (!SC->GetStartChange() && !SC->GetEndChange()) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			SC->SetEndChange();
		}
	}


}

void Title::Draw(Resources rs) {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	pressStart->MyDrawSpriteBlinking(rs.PressSpaceGH_);

	titleName->MyDrawSprite(rs.GameTitleGH_);
}