#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y; // ����. RectMakeCenter�� �̿��ϱ�� ��
	float _currentHP; float _maxHP;

public:
	enemy();
	~enemy();

	virtual HRESULT init(float x, float y)=0;
	// ����� ��ǥ�� �Է¹����� �Ű������� �߰��ҰŸ� enemy.h, �ٸ� ���Ŭ������� �����Ͽ� �ٲ��ָ� ��
	virtual void release();
	virtual void update();
	virtual void render();

	// ���������� ���̴� �Լ��� �� ����� �ϸ� ��
	RECT getRect() { return _rc; }

};
