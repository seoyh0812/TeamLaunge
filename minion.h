#pragma once
#include "enemy.h"

// Ŭ������ ���� �ȵ�� ���ֵ� ��. ���� ������ ���̴ϱ�..
class minion :	public enemy
{
private:

public:
	minion();
	~minion();
	int _plAtkNum;				//�׽�Ʈ�� �÷��̾� ���ݻ���

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void enemyState();				//���� �÷��̾��� ��ġ�� ���Ͽ� ���°��� ������
	void enemyStateRender();		//�������� ���� �����Լ��� ���� ������
	void keyManager();				//�׳� �� ���Ϸ����� �׽�Ʈ��
};
