#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "player.h"
#include "stageManager.h"
#include "itemManager.h"
#include "collision.h"
#include <vector>

class mainScene : public gameNode
{
private:
	enemyManager*	_em;
	stageManager*	_sm;
	itemManager*	_im;
	player*			_pl;
	collision*		_cl;

	vector<int> bottomY;
	char _str[128];
	RECT _loopRc;  int _loopX;	int _loopY; int _loopCount; // �޹�� ����������
	bool _mapChanging; // ���� �ٲ�� ������(���� �ö󰡴� ȿ��)
	int _timeLimit; int _timeCount; // ���ѽð�
	int _life;
	int _score;

public:
	mainScene();
	~mainScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void zOrderRender();
	void cameraControl();
	void uiRender();
	void plusScore(int x) { _score += x; }
};

