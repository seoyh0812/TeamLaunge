#include "stdafx.h"
#include "enemyManager.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	createMinion(CAMX+700, CAMY+500); // 제트오더 연습용으로 만들었으니 없애도 됨
	return S_OK;
}

void enemyManager::release()
{
	_vEnemy.clear();
}

void enemyManager::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		createBoss(_ptMouse.x, _ptMouse.y);
	}

	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->update();
	}
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->render();
	}
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
	vboss->init(x,y);
	_vEnemy.push_back(vboss);
}
