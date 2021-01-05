#include "stdafx.h"
#include "baseball.h"

baseball::baseball()
{
}

baseball::~baseball()
{
}

HRESULT baseball::init(float x, float y)
{
	_x = x;	_y = y;
	_rc = RectMakeCenter(_x, _y, 75, 75);
	return S_OK;
}

void baseball::release()
{
}

void baseball::update()
{
}

void baseball::render()
{
	Rectangle(getMemDC(), _rc);
	TextOut(getMemDC(), _rc.left, _rc.top, "抄 具备傍", strlen("抄 具备傍"));
}
