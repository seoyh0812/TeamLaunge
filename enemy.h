#pragma once
#include "gameNode.h"

enum enemyState { E_IDLE, E_WALK, E_ATK, E_DEAD, E_HIT, E_GRAB, E_FLYING, E_WALK2, E_SHAKE, E_FLYING2 };

class enemy : public gameNode
{
protected:
	RECT _rc;							//enemy�� ������ ����ϴ� ��Ʈ
	RECT _attackRc;						//enemy�� ������ ����ϴ� ��Ʈ
	RECT _shadow;						//enemy�� �׸��ڸ� ����ϴ� ��Ʈ

	float _x; float _y;					//enemy�� ����
	float _currentHP; float _maxHP;		//enemy�� ���� ü�°� �ִ� ü��

	int _count; int _index; int _index2;
	float _pX; float _pY;				//player�� ���� ��ǥ�� �޾ƿ������� �ʿ��� ����
	bool _left;							//enemy�� �¿츦 �Ǵ��ϴ� �� false == right, true == left
	bool _flying;						//enemy�� E_FLYING ���¿� ���������� ���� �浹�ϱ������� �����ִ� ���¸� üũ����
	bool _atkArea;						//enemy�� ���ݹ��� �ȿ� �����ߴ��� üũ����
	bool _isDead;						//enemy�� Ư�������� �޼��Ͽ� �׾�Ǵ� ���°� �Ǿ����� üũ����
	bool _flyDown;						//enemy�� E_FLYING2 ���¿��� ���߿� �����Ÿ��̻� ����ѵ� ���������ִ��� üũ����

	int _attackCount;					//enemy�� ������ �̷������ �������� �ð�
	int _hitCount;						//enemy�� E_HIT���� ����� �� ���� �����ð� 
	int _grabCount;						//enemy�� E_GRAB���� ����� �� ���� �����ð�
	int _plAtkNum;						//enemy1�� �ǰݽ� ��������� ������ �� �ְ� �������� ����ִ� ����
	int _randomNum;						//enemy�� player�� �����Ҷ� y�� ��ǥ�� ������ �־� enemy�� ��ġ���ʰԲ� ���ִ� ����
	int _deadCount;						//enemy2, 3�� �״� ����� �Ѱ��̱⶧���� �״¸�ǿ��� �����ð� ������ų �ʿ䰡�����Ƿ� ������Ű�� �ð��� �Է¹޴� ����
	int _alpha;							//enemy�� �̹��� ������ ���� ������ ����ϱ� ���� �ʿ��� ����
	int _phase;							//boss�� ����� �����ϱ� ���� �ʿ��� ����

	enemyState _state;					//enemy�� Ư�����¸� �ֱ����� �ʿ��� ���°� �Ǿ��ִ� ����
public:
	enemy();
	~enemy();

	virtual HRESULT init(float x, float y) = 0;
	virtual void release();
	virtual void update();
	virtual void render();
	void fillColorEllipse(int R, int G, int B, RECT rc);
	void setPlayerPt(float x, float y) { _pX = x; _pY = y; }
	void getDamage(int x) { _currentHP -= x; }
	void setState(enemyState state);
	void setAtkNum() { _plAtkNum = RND->getFromIntTo(1, 3); }
	void setAlpha() { _alpha = 255; }

	RECT& getRect() { return _rc; }
	RECT& getShadow() { return _shadow; }
	RECT& getAtkRc() { return _attackRc; }

	enemyState& getState() { return _state; }

	int getPhase() { return _phase; }
	float& getHp() { return _currentHP; }
	float getY() { return _y; }
	bool& getLeft() { return _left; }
	bool& getIsDead() { return _isDead; }

};
