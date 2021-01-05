#include "stdafx.h"
#include "Jump.h"
#include "player.h"

#define GRAVITY 0.2f

void Jump::EnterState()
{
	_pl->getFlyRc() = _pl->getGroundRc();
	_jumpPower = 5;
	// ���⼭ ���⿡���� �̹����ְ� �ε��� ���� �ʱ�ȭ����
}

void Jump::updateState()
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
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT))
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

	_jumpPower -= GRAVITY;
	_pl->getFlyY() -= _jumpPower; // �û� ���� �߷°� �����Ŀ�
	if (_pl->getFlyY() > _pl->getGroundY())
	{ // 
		_pl->getFlyY() = _pl->getGroundY();
		_pl->setState(IDLE);
	}
}

void Jump::ExitState()
{
}

