
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
	//���� Ŭ����(item) ����.
	_image = IMAGEMANAGER->findImage("��");//�̹��� ����
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
	_strach = false;
	_ID = 1;
	_food = false;
	return S_OK;
}

HRESULT baseball::init(float x, float y, float bottom)
{
	//���� Ŭ����(item) ����.
	_image = IMAGEMANAGER->findImage("��");//�̹��� ����
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
	_strach = false;
	_ID = 1;
	_food = false;
	return S_OK;
}

void baseball::release()
{
}

void baseball::update()
{
	if (!_pickup && !_moving) drop();

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());

	_distance = _yg - _y;//����Ʈ�� ���߷�Ʈ�� ��ġ����.

	//�׸��� ũ�� ����. �־����� �۾������� �մϴ�.
	int shadowWidth = _image->getWidth() - (_distance / 2);
	int shadowHeight = (_image->getHeight() / 3) - (_distance / 6);
	//0���� �۾����� ��������� �սô�.
	if (shadowWidth <= 10) shadowWidth = 10;
	if (shadowHeight <= 10)shadowHeight = 10;

	_shadow = RectMakeCenter(_xg, _rcg.bottom, shadowWidth, shadowHeight);

	if (_strach) _image = IMAGEMANAGER->findImage("��׷�����");
	else _image = IMAGEMANAGER->findImage("��");


	if (_strach)_time -= TIMEMANAGER->getElapsedTime();
	if (_time < 0)_strach = false;
	if (_pickup)
	{
		_xg = _x;//����Ʈ
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
	}
	if (_moving)
	{
		_xg = _x;//����Ʈ
		_rcg = RectMakeCenter(_xg, _yg, _image->getWidth(), _image->getHeight());//����Ʈ
	}
}

void baseball::render()
{
	fillColorEllipse(80, 80, 80, _shadow);
	//Rectangle(getMemDC(), _rcg);
	_image->render(getMemDC(), _x - (_image->getWidth() / 2), _rc.top);
	//TextOut(getMemDC(), _rc.left, _rc.top, "�� �߱���", strlen("�� �߱���"));
}

void baseball::drop()
{
	if (_yg > _y)
	{
		_gravity += 0.2f;
		_y += _gravity;
	}
	else if (_yg < _y)
	{
		_strach = true;
		_time = 1.0f / 5;
		_y = _yg;
	}
	else
	{
		_y = _yg;
	}
}

void baseball::setHold(float x, float y)
{
	_pickup = true;
	_x = x;
	_y = y;
}

void baseball::setHold(float x, float y, float bottom)
{
	_pickup = true;
	_x = x;
	_y = y;
	_yg = bottom - (_image->getHeight() / 2);
	_tall = _yg - _y;
}

void baseball::attackMove(bool direction)
{//�Ŵ������� ����� �Լ�.
	_pickup = false;
	_moving = true;
	_direction = direction;
	if (_direction == true)
	{
		_x += 17.2f;
	}
	else
	{
		_x -= 17.2f;
	}
	_y -= 10 * sinf(_angle);//�浹�� ƨ�ܳ����� ������ �ֱ�����.
	_yg -= 10 * sinf(_angle);
}
