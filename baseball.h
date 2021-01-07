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

	float _angle;

public:
	baseball();
	~baseball();

	//�⺻ �Լ�.

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
	//��ӹ޾� �������̵��ϴ� �Լ�.

	virtual void setHold(bool holding, float x, float y);
	virtual void attackMove(bool direction);

	//Ŭ���� ���� �Լ�

	void drop();
};

