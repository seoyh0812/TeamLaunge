#pragma once
#include "gameNode.h"

enum enemyState { E_IDLE, E_WALK, E_ATK, E_DEAD, E_HIT, E_GRAB, E_FLYING };
enum bossState { B_IDLE, B_WALK };

class enemy : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y; // ����. RectMakeCenter�� �̿��ϱ�� ��
	float _currentHP; float _maxHP;

	int _count; int _index;
	float _pX; float _pY; // �÷��̾� ����
	bool _left; // ������ ���� ������ 1, �������̸� 0. �� ��Ʈ�ĸ� _frameIndexYó�� �����̱� ����)
	int _attackCount;		// ������Ÿ��
	int _hitCount;			// �ǰݸ�� �����ð�
	int _grabCount;			// �׷���� �����ð�
	int _flyingCount;		// �ö��׸�� �����ð�
	bool _flying; // ���������� 1, �����̸� 0

	enemyState _state;
	bossState _bState;
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
