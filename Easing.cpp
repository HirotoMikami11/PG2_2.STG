﻿#include"Easing.h"

float EaseInSine(float x) {
	return 1 - cosf((x * float(M_PI)) / 2);
}

float EaseOutSine(float x) {
	return sinf((x * float(M_PI)) / 2);
}

float EaseInOutSine(float x) {
	return -(cosf(float(M_PI) * x) - 1) / 2;
}





float easeInQuad(float x) {
	return x * x;
}
float easeOutQuad(float x) {
	return 1 - (1 - x) * (1 - x);
}

float easeInOutQuad(float x) {
	return x < 0.5f ? 2 * x * x : 1 - powf(-2 * x + 2, 2) / 2;
}





float easeInCubic(float x) {
	return x * x * x;
}

float easeOutCubic(float x) {
	return 1 - powf(1 - x, 3);
}

float easeInOutCubic(float x) {
	return x < 0.5f ? 4 * x * x * x : 1 - powf(-2 * x + 2, 3) / 2;
}





float easeInQuart(float x) {
	return x * x * x * x;
}

float easeOutQuart(float x) {
	return 1 - powf(1 - x, 4);
}

float easeInOutQuart(float x) {
	return x < 0.5f ? 8 * x * x * x * x : 1 - powf(-2 * x + 2, 4) / 2;
}





float easeInQuint(float x) {
	return x * x * x * x * x;
}

float easeOutQuint(float x) {
	return 1 - powf(1 - x, 5);
}

float easeInOutQuint(float x) {
	return x < 0.5f ? 16 * x * x * x * x * x : 1 - powf(-2 * x + 2, 5) / 2;
}






float easeInExpo(float x) {
	return x == 0 ? 0 : powf(2, 10 * x - 10);
}

float easeOutExpo(float x) {
	return x == 1 ? 1 : 1 - powf(2, -10 * x);
}

float easeInOutExpo(float x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5f ? powf(2, 20 * x - 10) / 2
		: (2 - powf(2, -20 * x + 10)) / 2;
}





float easeInCirc(float x) {
	return 1 - sqrtf(1 - powf(x, 2));
}

float easeOutCirc(float x) {
	return sqrtf(1 - powf(x - 1, 2));
}

float easeInOutCirc(float x) {
	return x < 0.5f
		? (1 - sqrtf(1 - powf(2 * x, 2))) / 2
		: (sqrtf(1 - powf(-2 * x + 2, 2)) + 1) / 2;
}





float easeInBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;

	return c3 * x * x * x - c1 * x * x;
}

float easeOutBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;

	return 1 + c3 * powf(x - 1, 3) + c1 * powf(x - 1, 2);
}

float easeInOutBack(float x) {
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;

	return x < 0.5f
		? (powf(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (powf(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}





float easeInElastic(float x) {
	const float c4 = (2 * float(M_PI)) / 3;

	return x == 0
		? 0
		: x == 1
		? 1
		: -powf(2, 10 * x - 10) * sinf((x * 10 - 10.75f) * c4);
}

float easeOutElastic(float x) {
	const float c4 = (2 * float(M_PI)) / 3;

	return x == 0
		? 0
		: x == 1
		? 1
		: powf(2, -10 * x) * sinf((x * 10 - 0.75f) * c4) + 1;
}

float easeInOutElastic(float x) {
	const float c5 = (2 * float(M_PI)) / 4.5f;

	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5f
		? -(powf(2, 20 * x - 10) * sinf((20 * x - 11.125f) * c5)) / 2
		: (powf(2, -20 * x + 10) * sinf((20 * x - 11.125f) * c5)) / 2 + 1;
}





float easeInBounce(float x) {
	return 1 - easeOutBounce(1 - x);
}

float easeOutBounce(float x) {
	const float n1 = 7.5625;
	const float d1 = 2.75;

	if (x < 1 / d1) {
		return n1 * x * x;
	} else if (x < 2 / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	} else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	} else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}

float easeInOutBounce(float x) {
	return x < 0.5f
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}



