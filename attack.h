#pragma once
#include "gameNode.h"
#include <vector>



class player;

// �޺����ݿ� �� ���� �����Դϴ�.
struct tagAttack
{
	RECT rc;				//���ݿ� ���� ��Ʈ
	float x, y;				//���� ��ǥ
	float attackX, attackY;	//���� ��ġ
	bool isAttack;			//���� ����
};


class attack : public gameNode
{
private:
	vector<tagAttack> _vAttack;
	vector<tagAttack>::iterator _viAttack;

	int _count;
	int _attackMax; // ���� ��Ʈ �Ѱ�ġ. (��� �� �� ������ �־����ϴ�)
	player* _pl;

	RECT _attackRect; // ����_�ݸ������� �߰��Ѱ� 2

public:

	
	attack() {};
	~attack() {};

	HRESULT init(int attackMax, int count);
	void release();
	void update(int count);
	void render();

	void Attack(float x, float y);
	RECT getAttackRect() { return _attackRect; } // ����_�ݸ������� �߰��Ѱ� 3. ��.
	void removeAttack(int arrNum);

	vector<tagAttack> getVAttack()				{ return _vAttack; }
	vector<tagAttack>::iterator getViAttack() { return _viAttack; }
};