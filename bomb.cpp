#include "stdafx.h"
#include "bomb.h"

HRESULT bomb::init(float x, float y)
{
	_image = IMAGEMANAGER->findImage("��ź");
	_image->setFrameX(0);
	_image->setFrameY(0);
	_gravity = 3;
	_x = x;	_y = y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());//���߷�Ʈ
	_pickup = false;
	_moving = false;

	_xg = _x;
	_yg = _y + 70;
	_rcg = RectMakeCenter(_xg, _yg, _image->getFrameWidth(), _image->getFrameHeight());//����Ʈ
	_distance = _yg - _y;
	_shadow = RectMakeCenter(_xg, _rcg.bottom, _image->getFrameWidth() - (_distance / 2), (_image->getFrameHeight() - (_distance / 2) / 3));
	_time = 0;
	_delete = false;
	
	_index = 0;
	_indexTime = 0;

	_food = false;
	
	return S_OK;
}

void bomb::release()
{
}

void bomb::update()
{
	if (!_moving && !_pickup)
	{
		drop();
	}
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	_distance = _yg - _y;

	int shadowWidth = _image->getFrameWidth() - (_distance / 2);
	int shadowHeight = (_image->getFrameHeight() / 3) - (_distance / 6);
	if (shadowWidth <= 0) shadowWidth = 0;
	if (shadowHeight <= 0)shadowHeight = 0;

	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);
	
	_indexTime += TIMEMANAGER->getElapsedTime();
	if (_pickup)
	{
		_xg = _x;//����Ʈ
		_yg = _y + 30;
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
	}
	if (_moving)
	{
		_xg = _x;//����Ʈ
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
	}
}

void bomb::render()
{
	fillColorEllipse(80, 80, 80, _shadow);
	Rectangle(getMemDC(), _rc);
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}

void bomb::attackMove(bool direction)
{
	if (_pickup)_gravity = 5;
	drop(0.5f);
	_pickup = false;
	_moving = true;
	if (_y < _yg)
	{
		reverseFraming();
		if (direction == true)
		{
			_x += 9.7f;
			_xg += 9.7f;
		}
		else
		{
			_x -= 9.7f;
			_xg -= 9.7f;
		}
	}
	else _delete = true;
	
}



void bomb::setHold(float x, float y)
{
	_pickup = true;
	_x = x;
	_y = y;
	framing(0, 1);
}

void bomb::drop()
{
	if (_yg > _y)
	{
		_gravity -= 0.2f;
		_y -= _gravity;
		framing();
	}
	else 
	{
		_y = _yg;
		framing(0, 1);
	}
}

void bomb::drop(float g)
{
	if (_yg > _y)
	{
		_gravity -= g;
		_y -= _gravity;
		framing();
	}
	else
	{
		_y = _yg;
		framing(0, 1);
	}
}

void bomb::framing()
{
	float indexTime = 1.0f / 20;
	if (_indexTime > (indexTime))
	{
		if (_index > _image->getMaxFrameX()) _index = 0;
		_index++;
		_image->setFrameX(_index);
		_indexTime -= indexTime;
	}
	
}

void bomb::framing(int start, int end)
{
	float indexTime = 1.0f / 7;
	if (start < end)
	{
		if (_indexTime > (indexTime))
		{
			if (_index > end) _index = start;
			_image->setFrameX(_index);
			_index++;
			_indexTime -= indexTime;
		}
	}
	if (start > end)
	{
		if (_indexTime > (indexTime))
		{
			if (_index > start) _index = end;
			_image->setFrameX(_index);
			_index++;
			_indexTime -= indexTime;
		}
	}
	
}

void bomb::reverseFraming()
{
	float indexTime = 1.0f / 20;
	if (_indexTime > (indexTime))
	{
		if (_index < 0) _index = _image->getMaxFrameX();
		_image->setFrameX(_index);
		_index--;
		_indexTime -= indexTime;
	}
}

void bomb::reverseFraming(int start, int end)
{
	float indexTime = 1.0f / 7;
	if (start > end)
	{
		if (_indexTime > (indexTime))
		{
			if (_index < end) _index = start;
			_image->setFrameX(_index);
			_index--;
			_indexTime -= indexTime;
		}
	}
	if (start < end)
	{
		if (_indexTime > (indexTime))
		{
			if (_index < start) _index = end;
			_image->setFrameX(_index);
			_index--;
			_indexTime -= indexTime;
		}
	}
}
	
