#pragma once
#include "STATE.h"
class player;
class Jump :
    public STATE
{
private:
	float _jumpPower;
public:
	void EnterState(); // ������ �̴��ǿ���
	void updateState(); // ��� ������Ʈ
	void ExitState(); // ��������
};

