#pragma once
#include "item.h"
class baseball :	public item
{
private:
	RECT _rcg;
	float _xg, _yg;
	float _gravity;

	RECT _shadow;
	int _distance;
	float _time;
	BOOL _strach;
public:
	baseball();
	~baseball();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
	void move();
};

