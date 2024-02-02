#include "Box.h"

Box::Box(Vector2 pos, Vector2 size, unsigned int color) {
	pos_ = pos;
	size_ = size;
	color_ = color;
	Timer_ = 0;
}

Box::~Box() {

}

void Box::MyDrawSprite(int rs) {

	Novice::DrawSprite(
		static_cast<int>(pos_.x - size_.x / 2),
		static_cast<int>(pos_.y - size_.y / 2),
		rs,
		1.0f, 1.0f, 0.0f, color_
	);
}
void Box::MyDrawSpriteBlinking(int rs) {

	Timer_++;
	if (Timer_ >= 60) {
		if (color_ == WHITE) {
			color_ = 0x00000000;
		} else {
			color_ = WHITE;
		}
		Timer_ = 0;
	}

	Novice::DrawSprite(
		static_cast<int>(pos_.x - size_.x / 2),
		static_cast<int>(pos_.y - size_.y / 2),
		rs,
		1.0f, 1.0f, 0.0f, color_
	);

}
void Box::MyDrawSpriteWhite(Resources rs) {

	Novice::DrawSprite(
		static_cast<int>(pos_.x - size_.x / 2),
		static_cast<int>(pos_.y - size_.y / 2),
		rs.whiteGH_,
		size_.x, size_.y,
		0.0f,
		color_
	);

}