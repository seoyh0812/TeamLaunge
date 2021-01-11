#include "stdafx.h"
#include "run.h"
#include "player.h"

void run::EnterState()
{
}

void run::updateState()
{

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (!_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = true; // ����ٲ� ī��Ʈ �÷��ְ� ��������
		}
		_pl->getFlyX() -= 8;	_pl->getGroundX() -= 8;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = false; // ����ٲ� ī��Ʈ �÷��ְ� ����������
		}
		_pl->getFlyX() += 8;	_pl->getGroundX() += 8;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pl->getFlyY() -= 8;	_pl->getGroundY() -= 8;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pl->getFlyY() += 8;	_pl->getGroundY() += 8;
	}
    if (KEYMANAGER->isOnceKeyDown('Z'))
    {
        _pl->setState(SLIDE);
    }
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_pl->setState(TACKLE);
	}
	if (!KEYMANAGER->isStayKeyDown(VK_LEFT) &&
		!KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
		!KEYMANAGER->isStayKeyDown(VK_UP) &&
		!KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pl->setState(IDLE);
	}
}

void run::ExitState()
{
}
