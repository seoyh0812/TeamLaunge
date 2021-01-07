#include "stdafx.h"
#include "walk.h"
#include "player.h"

void walk::EnterState()
{
}

void walk::updateState()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (!_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = true; // ����ٲ� ī��Ʈ �÷��ְ� ��������
		}
		_pl->getFlyX() -= 3;	_pl->getGroundX() -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)&& !KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = false; // ����ٲ� ī��Ʈ �÷��ְ� ����������
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
	if (KEYMANAGER->isStayKeyDown('X'))
	{
		_pl->setState(JUMP);
	}
	if (!KEYMANAGER->isStayKeyDown(VK_LEFT) &&		!KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
		!KEYMANAGER->isStayKeyDown(VK_UP) &&		!KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pl->setState(IDLE);
	}
}

void walk::ExitState()
{
}
