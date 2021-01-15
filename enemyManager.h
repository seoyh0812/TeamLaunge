#pragma once
#include "gameNode.h"
#include <vector>
#include "boss.h"
#include "minion.h"
#include "minion2.h"
#include "minion3.h"

class player;
class enemyManager :	public gameNode
{
private:
	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;
	player* _pl;
	minion* _minion;
public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void createMinion(float x, float y);			//�̴Ͼ�1 ����(��ǥ��)
	void createMinion2(float x, float y);			//�̴Ͼ�2 ����(��ǥ��)
	void createMinion3(float x, float y);			//�̴Ͼ�3 ����(��ǥ��)
	void createBoss(float x, float y);				//���� ����(��ǥ��)


	vector<enemy*> getVEnemy() { return _vEnemy; }
	vector<enemy*>::iterator getViEnemy() { return _viEnemy; }

	void setLinkPlayer(player* player) { _pl = player; }		//�÷��̾�� ��������ֱ� ���� �Լ�
};

