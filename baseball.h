#pragma once
#include "item.h"
class baseball :	public item
{
private:
	BOOL _strach;

public:
	baseball();
	~baseball();

	//�⺻ �Լ�.

	virtual HRESULT init(float x, float y);
	virtual HRESULT init(float x, float y, float bottom);
	virtual void release();
	virtual void update();
	virtual void render();
	//��ӹ޾� �������̵��ϴ� �Լ�.

	virtual void setHold(float x, float y);
	virtual void setHold(float x, float y, float bottom);
	virtual void attackMove(bool direction);

	//Ŭ���� ���� �Լ�

	void drop();
};

