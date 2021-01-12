#include "stdafx.h"
#include "walk.h"
#include "player.h"

void walk::EnterState()
{
	_pl->getIndex() = 0;
}

void walk::updateState()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (!_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = true; // 방향바뀜 카운트 올려주고 왼쪽으로
		}
		_pl->getFlyX() -= 3;	_pl->getGroundX() -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)&& !KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = false; // 방향바뀜 카운트 올려주고 오른쪽으로
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

    if (KEYMANAGER->isOnceKeyDown('Z'))
    {
        _pl->setState(COMBO1);
    }

	if (KEYMANAGER->isOnceKeyDown('X'))
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
	_pl->getIndex() = 0;
}
