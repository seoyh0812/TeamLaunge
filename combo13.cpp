#include "stdafx.h"
#include "combo13.h"
#include "player.h"

void combo13::EnterState()
{
	_pl->getIndex() = 0;	
	if (!_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getGroundRc().right, _pl->getGroundRc().top); }
	if (_pl->getLeft()) { _pl->getAttack()->Attack(_pl->getGroundRc().left - 150, _pl->getGroundRc().top); }

	//콤보 각 행의 마지막 공격엔 기합소리를 넣어줬습니다
    SOUNDMANAGER->play("기합1");
}

void combo13::updateState()
{




}

void combo13::ExitState()
{
}
