#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_pl = new player;
	//���� ���̺� �ʱ� ����
	_wave = 1;
	//���� �������� üũ(���ѻ��� ����)
	_create = WAIT;
	
	return S_OK;
}

void enemyManager::createMinion(float x, float y)
{
	minion* vminion;
	vminion = new minion;
	vminion->init(x, y);
	_vEnemy.push_back(vminion);
}

void enemyManager::createMinion2(float x, float y)
{
	minion2* vminion2;
	vminion2 = new minion2;
	vminion2->init(x, y);
	_vEnemy.push_back(vminion2);
}

void enemyManager::createMinion3(float x, float y)
{
	minion3* vminion3;
	vminion3 = new minion3;
	vminion3->init(x, y);
	_vEnemy.push_back(vminion3);
}

void enemyManager::createBoss(float x, float y)
{
	boss* vboss;
	vboss = new boss;
	vboss->init(x, y);
	_vEnemy.push_back(vboss);
}

void enemyManager::release()
{
	_vEnemy.clear();
}

void enemyManager::update()
{
	
	//������� ��� ���ʹ̵��� ������Ʈ ����
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->update();
		_vEnemy[i]->setPlayerPt(_pl->getGroundX(), _pl->getGroundY());
	}

	//���Ͱ� ����������� ������ �̳����� üũ�Ͽ� ���� ���� ���� ����
	if (_wave == 1 && _create == WAIT)
	{
		//ù ���� ���̺�(�� ���� 3����)
		createMinion(900, 600);
		createMinion2(700, 500);
		createMinion3(700, 600);
		createBoss(1600, 400);
		_create = END;
	}
}

void enemyManager::render()
{ // ������ ��Ʈ�������� �ѹ��� �׸�����
}
