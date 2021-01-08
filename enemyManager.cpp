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
		//createMinion(CAMX + 1300, CAMY + 500);
		//createMinion(CAMX + 1300, CAMY + 600);
		//createBoss(1600, 400);
		//���� �׽�Ʈ
		_create = END;
	}
}

void enemyManager::render()
{ // ������ ��Ʈ�������� �ѹ��� �׸�����
}
