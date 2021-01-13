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
	_id = 0;
	_rc = RectMakeCenter(_x, _y, 233, 250);
	_chairRect = RectMakeCenter(_x, _y, 233, 250);
	_img = IMAGEMANAGER->findImage("의자");
	_isFire = true;
	_isBossOn = false;
	_chairShadow = RectMakeCenter(_x + 30, _rc.bottom + 105, 210, 50);


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

	shadowRender(_chairShadow);
	// Rectangle(getMemDC(), _rc);
	_img->render(getMemDC(), _rc.left - 50, _rc.top - 60);
	// TextOut(getMemDC(), _rc.left, _rc.top, "난 의자", strlen("난 의자"));
	if (KEYMANAGER->isToggleKey('O'))
	{
		//Rectangle(getMemDC(), _chairRect);
		Rectangle(getMemDC(), _rc);


	}
}

void chair::shadowRender(RECT rc)
{
	HPEN pen = CreatePen(0, 2, RGB(80, 80, 80));
	HPEN oldpen = (HPEN)SelectObject(getMemDC(), pen);
	HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
	HBRUSH oldbrush = (HBRUSH)SelectObject(getMemDC(), brush);

	Ellipse(getMemDC(), rc);

	SelectObject(getMemDC(), oldbrush);
	DeleteObject(brush);
	SelectObject(getMemDC(), oldpen);
	DeleteObject(pen);
}
