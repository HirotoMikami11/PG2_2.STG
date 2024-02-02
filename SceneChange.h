#pragma once
#include<MyMath.h>
#include<Easing.h>
#include"Scene.h"
class SceneChange {


	bool isStartChange_;
	bool isEndChange_;
	bool isGameClear_;
	bool isGameOver_;


	/*暗転変数*/
	float CT_;
	float addCT_;

	float CEaseTimer_;
	float CEaseDir_;
	float maxCColor_;
	float minCColor_;
	float addCColor_;
	unsigned int CColor_;

	int CWaitTimer_;
	int CWaitMaxTimer_;

	/*チュートリアルからゲーム本編の暗転変数*/
	float CtoGT_;
	float addCtoGT_;

	float CtoGEaseTimer_;
	float CtoGEaseDir_;
	float maxCtoGColor_;
	float minCtoGColor_;
	float addCtoGColor_;
	unsigned int CtoGColor_;
public:

	SceneChange();
	~SceneChange();
	void Update();
	void Draw();
	void Reset();

	//アクセッサ
	bool GetStartChange() { return isStartChange_; };
	bool GetEndChange() { return isEndChange_; };
	bool GetGameClear() { return isGameClear_; };
	bool GetGameOver() { return isGameOver_; };

	void SetStartChange() { isStartChange_=true; };
	void SetEndChange() { isEndChange_=true; };
	void SetGameClear() { isGameClear_=true; };
	void SetGameOver() { isGameOver_=true; };
};

