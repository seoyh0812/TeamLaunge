#pragma once
#include "enemy.h"

class minion3 : public enemy
{
private:

public:
	minion3();
	~minion3();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void enemyState();				//enemy�� ���¿����� Ư������� ��������ִ� �Լ�
	void enemyStateRender();		//enemy�� ���¿����� ������ �������ִ� �Լ�
};

