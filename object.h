#pragma once
#include "gameNode.h"
#include <vector>

// ��� �θ�Ŭ����

class object : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y;

public:
	object();
	~object();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	RECT getRect() { return _rc; }
};

