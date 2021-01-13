#include "stdafx.h"
#include "hit.h"
#include "player.h"

void hit::EnterState()
{
    _pl->getIndex() = 0;
}

void hit::updateState()
{
    _pl->getIsHit() = true;
}

void hit::ExitState()
{
    _pl->getIsHit() = false;
}
