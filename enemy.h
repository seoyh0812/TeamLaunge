#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y; // 중점. RectMakeCenter를 이용하기로 함
	float _currentHP; float _maxHP;

public:
	enemy();
	~enemy();

	virtual HRESULT init(float x, float y)=0;
	// 선언시 좌표를 입력받지만 매개변수를 추가할거면 enemy.h, 다른 상속클래스들과 통일하여 바꿔주면 됨
	virtual void release();
	virtual void update();
	virtual void render();

	// 공통적으로 쓰이는 함수는 다 여기다 하면 돼
	RECT getRect() { return _rc; }

};
