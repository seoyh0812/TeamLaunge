#pragma once
#include "enemy.h"

// Ŭ������ ���� �ȵ�� ���ֵ� ��. ���� ������ ���̴ϱ�..
class minion :	public enemy
{
private:

public:
	minion();
	~minion();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	//void imageRect();				//�̹������¿� ���� ��Ʈũ�⸦ ��ȯ��
	void move();					//���� �������� ������
	void enemyState();				//���� �÷��̾��� ��ġ�� ���Ͽ� ���°��� ������
};
