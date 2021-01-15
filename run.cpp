#include "stdafx.h"
#include "run.h"
#include "player.h"

void run::EnterState()
{
    _pl->getIndex() = 0;
}

void run::updateState()
{

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (!_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = true; //����Ű�� �Է��ϸ� isLeft �Ұ��� Ʈ��� ����� ������ ���� ��������ϴ�.
		}
		_pl->getFlyX() -= 8;	_pl->getGroundX() -= 8;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pl->getLeft())
		{
			_pl->plusDirectionChanged();
			_pl->getLeft() = false; // �ݴ�� ���������� ���� ��������ϴ�.
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

    if (_pl->getIsGrab()) // �÷��̾��� isGrab�� Ʈ���� ���¸� �׷����� �ٲٰ� �߽��ϴ�.
    {
        _pl->setState(GRAB);
    }

    if (KEYMANAGER->isOnceKeyDown('Z')) // �޸��� �߿� ZŰ�� ������ �����̵�
    {
        _pl->setState(SLIDE);
    }
	if (KEYMANAGER->isOnceKeyDown('X')) // �ƴϸ� ��Ŭ�� �����ϰ� �߽��ϴ�.
	{
		_pl->setState(TACKLE);
	}
	if (!KEYMANAGER->isStayKeyDown(VK_LEFT) &&
		!KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
		!KEYMANAGER->isStayKeyDown(VK_UP) &&
		!KEYMANAGER->isStayKeyDown(VK_DOWN)) // ����Ű�� �׸� �Է��ϸ� idle�� ���ư��� �߽��ϴ�.
	{
		_pl->setState(IDLE);
	}
}

void run::ExitState()
{
}
