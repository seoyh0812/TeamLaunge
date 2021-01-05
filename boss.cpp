#include "stdafx.h"
#include "boss.h"

boss::boss()
{
}

boss::~boss()
{
}

HRESULT boss::init(float x, float y)
{
	_x = x;	_y = y;
	_currentHP = _maxHP = 500;
	_rc=RectMakeCenter(_x, _y, 100, 100);
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	move();
}

void boss::render()
{
	Rectangle(getMemDC(), _rc);
	TextOut(getMemDC(), _rc.left, _rc.top, "�� ����", strlen("�� ����"));
}

void boss::move()
{ // �ɽ��ؼ� �ε�ε� �־����� ���ֵ� ����
	_y += rand()%11 -5;
	if (_y > WINSIZEY || _y < 0) _y = WINSIZEX / 2;
	_rc = RectMakeCenter(_x, _y, 100, 100);
}
