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
	_rc = RectMakeCenter(_x, _y, 233, 250);
	_ChairImg = IMAGEMANAGER->findImage("����");
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
	// Rectangle(getMemDC(), _rc);
	_ChairImg->render(getMemDC(), _rc.left, _rc.top);
	TextOut(getMemDC(), _rc.left, _rc.top, "�� ����", strlen("�� ����"));
}
