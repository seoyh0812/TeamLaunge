#include "stdafx.h"
#include "Idle.h"
#include "player.h"
void Idle::EnterState()
{
	// ���⿡���� �̹����ְ� �ε��� ���� �ʱ�ȭ����
	//_player->setMainImg("�����Ϲݻ���");
    _pl->getJumpPower() = 15;
	
}

void Idle::updateState()
{
	// �����¿� Ű�Է��� �ϸ� �װ� ��� �����ص�.
	// 30ī��Ʈ�� ������ ������ ���� �ٽ� 0���� �ʱ�ȭ��.
	// �㳪, 30ī��Ʈ(0.5��)������ �� �װ� �ٽ� ������ ���� �ʰ� �ٵ��� �����ص׾�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_pl->getDirMemory() != 1) // �����س����� 1�� �ƴ϶��
		{
			_pl->getDirMemory() = 1; // ���� ���°� �������̶�� ����
			_pl->setState(WALK); // �ȵ��� �Ͽ���
		}
		else // �����صа� 1�̶��. �� 1�� ���޾� �ι� ���� ����
		{
			_pl->setState(RUN); // �ٵ��� �Ͽ���
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

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_pl->setState(COMBO1);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_pl->setState(JUMP);
	}
}

void Idle::ExitState()
{

}
