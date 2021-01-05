#include "stdafx.h"
#include "chair.h"

chair::chair()
{
}

chair::~chair()
{
}

HRESULT chair::init(float x, float y)
{
	_x = x;	_y = y;
	_rc = RectMakeCenter(_x, _y, 90, 90);
	return S_OK;
}

void chair::release()
{
}

void chair::update()
{
}

void chair::render()
{
	Rectangle(getMemDC(), _rc);
	TextOut(getMemDC(), _rc.left, _rc.top, "난 의자", strlen("난 의자"));
}
