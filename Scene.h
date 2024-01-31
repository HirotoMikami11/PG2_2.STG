#pragma once
#include"MyMath.h"
enum SCENE {
	TITLE,
	GAME,
	CLEAR,
	OVER
};

class Scene {
public:

	//現在のシーン管理用変数
	static int SceneNum_;
	Scene();
	~Scene();
}
;

