#pragma once
#include "enemy.h"
class boss :public enemy
{
private:
	int _phaseCount;
	int _destX; // ������
	int _destY; // ������. ����������2�϶� �׸�����ġ�ε� ��
	bool _jumping; // ����
	int _rideCount;
	int _shakeCount; // �� 3�������� ���� �Ͼ
public:
	boss();
	~boss();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
	void bossState();			//������ ���°� ����
	void phase1();
	void phase2();
};

