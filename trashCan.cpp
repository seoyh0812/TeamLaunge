#include "stdafx.h"
#include "trashCan.h"

trashCan::trashCan()
{
}

trashCan::~trashCan()
{
}

HRESULT trashCan::init(float x, float y)
{
	_x = x; _y = y;
	_id = 1; // �ο����� id ()
	_rc = RectMakeCenter(_x, _y, 110, 150);
	_img = IMAGEMANAGER->findImage("��������");
	_isFire = true;
	return S_OK;
}

void trashCan::release()
{
}

void trashCan::update()
{
}

void trashCan::render()
{
//	Rectangle(getMemDC(), _rc);
	_img->render(getMemDC(), _rc.left,  _rc.top);
//	TextOut(getMemDC(), _rc.left, _rc.top, "��������", strlen("��������"));
}
