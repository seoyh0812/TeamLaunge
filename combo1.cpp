#include "stdafx.h"
#include "combo1.h"
#include "player.h"

void combo1::EnterState()
{
	_pl->getIndex() = 0;
	// �������̸� �����ʺ��� ���� ������ŭ �����ϰ�
	if (!_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getGroundRc().right, _pl->getGroundRc().top); }
	// �����̸� ���ʺ��� ���� ������ŭ ���� �����ϰ�
	if (_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getGroundRc().left - 150, _pl->getGroundRc().top); }
}

void combo1::updateState()
{
	
	

    if ((KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)) && KEYMANAGER->isOnceKeyDown('Z'))
    {
        _pl->setState(COMBO21);
    }

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_pl->setState(COMBO11);
	}

}

void combo1::ExitState()
{
}
