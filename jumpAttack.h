#pragma once
#include "STATE.h"

class player;
class jumpAttack : public STATE
{
private:
public:
    void EnterState(); // ������ �̴��ǿ���
    void updateState(); // ��� ������Ʈ
    void ExitState(); // ��������
};
