#pragma once
#include "gameNode.h"


class item :public gameNode
{
protected:
	RECT _rc;
	float _x; float _y;

public:
	item();
	~item();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	RECT getRect() { return _rc; }
};

