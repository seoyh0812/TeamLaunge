#pragma once
#include "gameNode.h"

enum enemyState { E_IDLE, E_WALK, E_ATK, E_DEAD, E_HIT, E_GRAB, E_FLYING, E_WALK2, E_SHAKE };
enum bossState { B_IDLE, B_WALK, B_ATK, B_DEAD, B_HIT, B_GRAB, B_FLYING};

class enemy : public gameNode
{
protected:
	RECT _rc;
	float _x; float _y; // ����. RectMakeCenter�� �̿��ϱ�� ��
	float _currentHP; float _maxHP;

	int _count; int _index; int _index2;
	float _pX; float _pY; // �÷��̾� ����
	bool _left; // ������ ���� ������ 1, �������̸� 0. �� ��Ʈ�ĸ� _frameIndexYó�� �����̱� ����)
	int _attackCount;			// ������Ÿ��
	int _hitCount;				// �ǰݸ�� �����ð�
	int _grabCount;				// �׷���� �����ð�
	bool _flying;					 // ���������� 1, �����̸� 0
	int _plAtkNum;					//�׽�Ʈ�� �÷��̾� ���ݻ���
	int _keyManagerNum;				//Ű�Ŵ��� ���� ���û���
	bool _atkArea;					//���� 1 ���ݹ��� �ȿ��� �����ϼ� �ְ� üũ����
	int _randomNum;					//���� y��ǥ ������ ���� (��ġ���ʰ��ϱ�����)

	RECT _shadow;

	enemyState _state;
	enemyState _state2;
	enemyState _state3;
	bossState _bState;
public:
	enemy();
	~enemy();

	virtual HRESULT init(float x, float y)=0;
	// ����� ��ǥ�� �Է¹����� �Ű������� �߰��ҰŸ� enemy.h, �ٸ� ���Ŭ������� �����Ͽ� �ٲ��ָ� ��
	virtual void release();
	virtual void update();
	virtual void render();
	void fillColorEllipse(int R, int G, int B, RECT rc);

	// ���������� ���̴� �Լ��� �� ����� �ϸ� ��
	RECT& getRect() { return _rc; }
	RECT& getShadow() { return _shadow; }
	void setPlayerPt(float x, float y) { _pX = x; _pY = y; }
};
