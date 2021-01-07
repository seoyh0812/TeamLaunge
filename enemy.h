#pragma once
#include "gameNode.h"

enum enemyState
{
	E_IDLE_L, E_IDLE_R,
	E_WALK_L, E_WALK_R,
	E_ATK_L, E_ATK_R,
	E_DEAD_L, E_DEAD_R
};

class enemy : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y; // ����. RectMakeCenter�� �̿��ϱ�� ��
	float _currentHP; float _maxHP;

	int _count; int _index;
	enemyState _state;
	float _pX; float _pY; // �÷��̾� ����

public:
	enemy();
	~enemy();

	virtual HRESULT init(float x, float y)=0;
	// ����� ��ǥ�� �Է¹����� �Ű������� �߰��ҰŸ� enemy.h, �ٸ� ���Ŭ������� �����Ͽ� �ٲ��ָ� ��
	virtual void release();
	virtual void update();
	virtual void render();

	// ���������� ���̴� �Լ��� �� ����� �ϸ� ��
	RECT& getRect() { return _rc; }
	void setPlayerPt(float x, float y) { _pX = x; _pY = y; }
};
