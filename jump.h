#pragma once
#include "STATE.h"
class player;
class Jump :
    public STATE
{
private:
public:
	void EnterState(); // ������ �̴��ǿ���
	void updateState(); // ��� ������Ʈ
	void ExitState(); // ��������
};

