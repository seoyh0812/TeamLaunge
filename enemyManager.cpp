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
	return S_OK;
}

void enemyManager::createMinion(float x, float y)
{
	minion* vminion;
	vminion = new minion;
	vminion->init(x, y);
	_vEnemy.push_back(vminion);
	if(!SOUNDMANAGER->isPlaySound("적등장1")) SOUNDMANAGER->play("적등장1");
}

void enemyManager::createMinion2(float x, float y)
{
	minion2* vminion2;
	vminion2 = new minion2;
	vminion2->init(x, y);
	_vEnemy.push_back(vminion2);
	if (!SOUNDMANAGER->isPlaySound("적등장2")) SOUNDMANAGER->play("적등장2");
}

void enemyManager::createMinion3(float x, float y)
{
	minion3* vminion3;
	vminion3 = new minion3;
	vminion3->init(x, y);
	_vEnemy.push_back(vminion3);
	if (!SOUNDMANAGER->isPlaySound("적등장1")) SOUNDMANAGER->play("적등장1");
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
	//만들어진 모든 에너미들의 업데이트 연산
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->update();
		_vEnemy[i]->setPlayerPt(_pl->getGroundX(), _pl->getGroundY());
	}

	//E_DEAD상태가 되면 프레임이미지가 모두 순환하고 or 0.5초가 경과한 뒤 _isDead가 트루가 되며 벡터가 삭제됨
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getState() == E_DEAD && _vEnemy[i]->getIsDead())
		{
			_vEnemy.erase(_vEnemy.begin() + i);
			break;
		}
	}
}

void enemyManager::render()
{
}
