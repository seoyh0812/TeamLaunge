#pragma once
#include "gameNode.h"

enum enemyState { E_IDLE, E_WALK, E_ATK, E_DEAD, E_HIT, E_GRAB, E_FLYING, E_WALK2, E_SHAKE, E_FLYING2 };

class enemy : public gameNode
{
protected:
	RECT _rc;
	RECT _attackRc;
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
	bool _isDead;					//���Ͱ� �׾����� ��Ҵ��� ���� üũ
	int _deadCount;					//�״� ����� 1���� ��� �װ� �� ���� �����ð��� �����ϱ����� ����
	int _flyingCount;				//ü���ð��� üũ�Ϸ��� ����
	bool _flyDown;					
	int _alpha;

	RECT _shadow;

	enemyState _state;
	enemyState _bState;
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
	RECT& getAtkRc() { return _attackRc; }
	float& getHp() { return _currentHP; }
	bool& getIsDead() { return _isDead; }
	enemyState& getState() { return _state; }
	void setPlayerPt(float x, float y) { _pX = x; _pY = y; }
	void getDamage(int x) { _currentHP -= x; }
	void setState(enemyState state);
	float getY() { return _y; }
	void setAtkNum() { _plAtkNum = RND->getFromIntTo(1, 3); }
	bool& getLeft() { return _left; }
};
