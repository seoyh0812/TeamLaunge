#pragma once
#include "STATE.h"
class player;
class Idle :
    public STATE
{
private:
public:
    void EnterState();
    void updateState();
    void ExitState();
};

//�� ���¿��� �ϴ� STATE ������޴°� �翬�ѵ�
//�÷��̾� Ŭ������ ��ȣ���������� ��ư ������ ���漱�����������