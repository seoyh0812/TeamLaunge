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
	//상위 클래스(item) 변수.
	_image = IMAGEMANAGER->findImage("공");
	_gravity = -4;
	_x = x;	_y = y;
	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());//공중렉트
	
	//하위 클래스(ball) 변수.
	_xg = _x;
	_yg = _y + 70;
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//땅렉트
	_distance = _yg - _y;
	_shadow = RectMakeCenter(_xg, _rcg.bottom, _image->getWidth() -(_distance /2), _image->getHeight()/3);
	_time = 0;
	_strach = false;
	return S_OK;
}

void baseball::release()
{
}

void baseball::update()
{
	move();
	
	//_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());

	_distance = _yg - _y;//땅렉트랑 공중렉트랑 위치차이.
	
	//그림자 크기 조절. 멀어지면 작아지도록 합니다.
	int shadowWidth = _image->getWidth() - (_distance / 2);
	int shadowHeight = (_image-> getHeight() / 3) - (_distance / 6);
	//0보다 작아지면 사라지도록 합시다.
	if (shadowWidth <= 0) shadowWidth = 0;
	if (shadowHeight <= 0)shadowHeight = 0;

	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);
	
	if (_strach) _image = IMAGEMANAGER->findImage("찌그러진공");
	else _image = IMAGEMANAGER->findImage("공");


	
	if (_strach)_time -= TIMEMANAGER->getElapsedTime();
	if (_time < 0)_strach = false;

}

void baseball::render()
{
	fillColorEllipse(80, 80, 80, _shadow);
	_image->render(getMemDC(), _rc.left, _rc.top);
	//Rectangle(getMemDC(), _rc);
	//TextOut(getMemDC(), _rc.left, _rc.top, "난 야구공", strlen("난 야구공"));
}

void baseball::move()
{
	if (_yg > _y)
	{
		_gravity += 0.2f;
		_y += _gravity;
		_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	}
	else if (_yg < _y)
	{
		_strach = true;
		_time = 1.0f / 5;
		_y = _yg;
		_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	}
	else
	{
		_y = _yg;
		_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	}
}
