#pragma once
#include "enemy.h"

class minion2 : public enemy
{
private:

public:
	minion2();
	~minion2();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void enemyState();				//���� �÷��̾��� ��ġ�� ���Ͽ� ���°��� ������
	void enemyStateRender();		//�������� ���� �����Լ��� ���� ������
	void keyManager();				//�׳� �� ���Ϸ����� �׽�Ʈ��
};

