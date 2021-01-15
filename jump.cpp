#include "stdafx.h"
#include "Jump.h"
#include "player.h"

#define GRAVITY 0.6f

void Jump::EnterState()
{
	_pl->getFlyRc() = _pl->getGroundRc();
}

void Jump::updateState()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (!_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = true;
		}
		_pl->getFlyX() -= 3;	_pl->getGroundX() -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = false;
		}
		_pl->getFlyX() += 3;	_pl->getGroundX() += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pl->getFlyY() -= 3;	_pl->getGroundY() -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pl->getFlyY() += 3;	_pl->getGroundY() += 3;
	}

    _pl->getJumpPower() -= GRAVITY;
    _pl->getFlyY() -= _pl->getJumpPower(); // �߷¸�ŭ �����Ŀ��� ���� ����Ʈ�� �ڿ������� �����ϴ°�ó�� ���̰� ��������ϴ�
	if (_pl->getFlyY() > _pl->getGroundY()) // �������� ��Ʈ�� ���� �ִ� ��Ʈ���� �������ٸ� ���¸� �ٲٰ� ������ ��ġ�� ���� ������ϴ�
	{ 
		_pl->getFlyY() = _pl->getGroundY();
		_pl->setState(IDLE);
	}

    if (KEYMANAGER->isOnceKeyDown('Z'))
    {
        _pl->setState(JUMPATTACK);
    }
}

void Jump::ExitState()
{
}

