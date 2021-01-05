#include "stdafx.h"
#include "minion.h"

minion::minion()
{
}

minion::~minion()
{
}

HRESULT minion::init(float x, float y)
{
	_x = x;	_y = y;
	_currentHP = _maxHP = 100;
	_rc = RectMakeCenter(_x, _y, 50, 50);
	return S_OK;
}

void minion::release()
{
}

void minion::update()
{
}

void minion::render()
{
	Rectangle(getMemDC(), _rc);
	TextOut(getMemDC(), _rc.left, _rc.top, "³­ ÂÌº´", strlen("³­ ÂÌº´"));
}
