#include "stdafx.h"
#include "combo12.h"
#include "player.h"

void combo12::EnterState()
{
	_pl->getIndex() = 0;
}

void combo12::updateState()
{

	if (!_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getFlyRc().right, (_pl->getFlyRc().bottom + _pl->getFlyRc().top) / 2); }
	if (_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getFlyRc().left - 150, (_pl->getFlyRc().bottom + _pl->getFlyRc().top) / 2); }
	
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_pl->setState(COMBO13);
	}

}

void combo12::ExitState()
{
}