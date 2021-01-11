#include "stdafx.h"
#include "bat.h"


bat::bat()
{
}

bat::~bat()
{
}

HRESULT bat::init(float x, float y)
{
	//���� Ŭ����(item) ����.
	_image = IMAGEMANAGER->findImage("��Ʈ");//�̹��� ����
	_gravity = -3;//�߷�
	_x = x;	_y = y;//���߷�Ʈ �߽�
	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());//���߷�Ʈ

	_pickup = false;//������� ����.
	_moving = false;//�������� ����.

	_xg = _x;//����Ʈ
	_yg = _y + 70;
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ

	_distance = _yg - _y;//��Ʈ�� �Ÿ�.
	int shadowWidth = _image->getWidth() - (_distance / 2);
	int shadowHeight = (_image->getHeight() / 3) - (_distance / 6);
	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);//�׸��� ��¿�.
	_time = 0;
	_angle = 0;
	
	_ID = 0;
	_food = false;
	return S_OK;
}

HRESULT bat::init(float x, float y, float bottom)
{
	_image = IMAGEMANAGER->findImage("��Ʈ");//�̹��� ����
	_gravity = -3;//�߷�
	_x = x;	_y = y;//���߷�Ʈ �߽�
	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());//���߷�Ʈ

	_pickup = false;//������� ����.
	_moving = false;//�������� ����.

	_xg = _x;//����Ʈ
	_yg = bottom;
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ

	_distance = _yg - _y;//��Ʈ�� �Ÿ�.
	int shadowWidth = _image->getWidth() - (_distance / 2);
	int shadowHeight = (_image->getHeight() / 3) - (_distance / 6);
	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);//�׸��� ��¿�.
	_time = 0;
	_angle = 0;

	_ID = 0;
	_food = false;
	return S_OK;
}

void bat::release()
{
}

void bat::update()
{
	if (!_pickup && !_moving) drop();

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());

	_distance = _yg - _y;//����Ʈ�� ���߷�Ʈ�� ��ġ����.

	//�׸��� ũ�� ����. �־����� �۾������� �մϴ�.
	int shadowWidth = _image->getWidth() - (_distance / 2);
	int shadowHeight = (_image->getHeight() / 3) - (_distance / 6);
	//0���� �۾����� ��������� �սô�.
	if (shadowWidth <= 0) shadowWidth = 0;
	if (shadowHeight <= 0)shadowHeight = 0;

	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);

	if (_pickup)
	{
		_xg = _x;//����Ʈ
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
		_time += TIMEMANAGER->getElapsedTime();
	}
	if (_moving)
	{
		_xg = _x;//����Ʈ
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
	}
	if (_time > 3)
	{
		//�������� �Լ�
	}
}

void bat::render()
{
	fillColorEllipse(80, 80, 80, _shadow);
	//Rectangle(getMemDC(), _rcg);
	_image->render(getMemDC(), _x - (_image->getWidth() / 2), _rc.top);
}

void bat::drop()
{
	if (_yg > _y)
	{
		_gravity += 0.2f;
		_y += _gravity;
	}
	else
	{
		_y = _yg;
	}
}

void bat::setHold(float x, float y)
{
	_pickup = true;
	_x = x;
	_y = y;
}

void bat::setHold(float x, float y, float bottom)
{
	_pickup = true;
	_x = x;
	_y = y;
	_yg = bottom - (_image->getHeight() / 2);
	_tall = _yg - _y;
}

void bat::attackMove(bool direction)
{//�Ŵ������� ����� �Լ�.
	if (_pickup)
	{
		_gravity = -3;
		_yg -= (RND->getFromIntTo(3, 9))*10;
	}
	_pickup = false;
	if (_yg > _y)
	{
		drop();
		_moving = true;
		if (direction == true)
		{
			_x += 6.2f;
		}
		else
		{
			_x -= 6.2f;
		}
	}
	else
	{
		_moving = false;
	}
}
