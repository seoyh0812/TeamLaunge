#include "stdafx.h"
#include "Idle.h"
#include "player.h"
void Idle::EnterState()
{
	//���¿� ������ �� ���¸��� �ʱ�ȭ�� ���ݴϴ� 
	//������ ���¿� ���� �̹��� ����� ���� index�� �ʱ�ȭ�ϰų� ������ ���� jumpPower �ʱ�ȭ ���� ������ϴ�
	_pl->getJumpPower() = 15;
	
}

void Idle::updateState()
{
	count++;
	// �����¿� Ű�Է��� �ϸ� �װ� ��� �����ص� ��
	// 30ī��Ʈ�� ������ ������ ���� �ٽ� 0���� �ʱ�ȭ �˴ϴ�
	// 30ī��Ʈ(0.5��)������ �� ���Է��ϸ� �޸��� ���°� �ǰ� ������ϴ�

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_pl->getDirMemory() != 1) // �����س����� 1�� �ƴ϶��
		{
			_pl->getDirMemory() = 1; // ���� ���°� �������̶�� ����
			_pl->setState(WALK); // �ȵ��� �Ͽ����ϴ�
		}
		else // �����صа� 1�̶��. �� 1�� ���޾� �ι� ���� ���
		{
			_pl->setState(RUN); // �ٵ��� �Ͽ����ϴ�
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getDirMemory() != 2)
		{
			_pl->getDirMemory() = 2;
			_pl->setState(WALK);
		}
		else
		{
			_pl->setState(RUN);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_pl->getDirMemory() != 3)
		{
			_pl->getDirMemory() = 3;
			_pl->setState(WALK);
		}
		else
		{
			_pl->setState(RUN);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_pl->getDirMemory() != 4)
		{
			_pl->getDirMemory() = 4;
			_pl->setState(WALK);
		}
		else
		{
			_pl->setState(RUN);
		}
	}

    if (_pl->getIsGrab())
    {
        _pl->setState(GRAB);
    }

    if (_pl->getDirectionChanged() >= 2 && KEYMANAGER->isOnceKeyDown('Z'))
    {
        _pl->setState(WINDMILL);
    }

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_pl->setState(COMBO1);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_pl->setState(JUMP);
	}

	if (count >= 120) // ī��Ʈ�� �� 2�ʰ� �Ǹ� ��������� �Ѿ�� ������ϴ�
	{
		_pl->setState(CIDLEANIMATION);
	}


}

void Idle::ExitState()
{
	count = 0; // ���¸� Ż���Ҷ� ����ǿ� ī��Ʈ�� �ʱ�ȭ�ϰ� �߽��ϴ�.
}
