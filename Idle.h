#pragma once
#include "STATE.h"
class player;
class Idle :
    public STATE
{
private:
	int count;
public:
    void EnterState();
    void updateState();
    void ExitState();
};

//�� ���¿��� STATE Ŭ������ ��ӹް� player Ŭ������ ��ȣ���� �ϱ� ���� ���漱�� �߽��ϴ�