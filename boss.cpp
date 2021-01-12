#include "stdafx.h"
#include "boss.h"

boss::boss()
{
}

boss::~boss()
{
}

void boss::bossState()
{
	//HIT���¿����� hitī��Ʈ�� ��������
	if (_state == E_HIT) _hitCount++;
	//GRAB���¿����� grabī��Ʈ�� ��������
	if (_state == E_GRAB) _grabCount++;

	//���ݹ��� �ȿ� �÷��̾ �ִ��� üũ��, �÷��̾�� ���ʹ��� ������ 100�̸��̸� true
	if (getDistance(_x, _y, _pX, _pY) < 100) _atkArea = true;
	//������ 100�̻��̸� false
	if (getDistance(_x, _y, _pX, _pY) >= 100) _atkArea = false;


	if (_phaseCount > 400) // ������ �ٲ�
	{
		_phase = 1 + rand() % 2;
		_destX = _pX;	_destY = _pY; // ����������
		_jumping = true;
		_phaseCount = _rideCount = 0; _index = 0;
		_state = E_WALK;
		if (_destX > _x) _left = false;
		else _left = true;
		return;
	}

	//���¸��� ����� ������
	switch (_state)
	{
	case E_SHAKE:
		if (_index > 2)
		{
			if (_shakeCount > 3)
			{
				_state = E_WALK;
				_index = 3;
				break;
			}
			_index = 0;
			++_shakeCount;
		}
		break;
	case E_IDLE:
		//������ �̹����� �ִ� �������� �ʰ����� �ʵ��� ��������
		if (_index > 0) _index = 0;

		//�÷��̾�� ���ʹ��� �Ÿ��� 100�̻��϶�
		if (getDistance(_x, _y, _pX, _pY) >= 100)
		{
			//�÷��̾ ���ʹ��� �����ʿ� �ִٸ�
			if (_x > _pX)
			{
				//���ʹ̴� ������ �����ִٰ� �������ְ� WALK���·� ���� �� 
				//�ִϸ��̼��� ó������ ó���ϱ����� �ε����� 0���� �ʱ�ȭ
				_left = true;
				_state = E_WALK;
				_index = 0;
			}
			else
			{
				//������ �����ʵ� ����
				_left = false;
				_state = E_WALK;
				_index = 0;
			}
		}
		break;

	case E_WALK:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ʱ�ȭ����
		if (_index > 3) _index = 0;
		//�÷��̾�� ���ʹ��� �Ÿ��� 200���϶�� ATK���·� ���� ��
		//�̹����� ó������ �����ϱ����� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) <= 200)
		{
			_attackCount++;
			if (_attackCount > 45)
			{
				_state = E_ATK;
				_index = 0;
				_attackCount = 0;
			}
		}
		//�÷��̾�� ���ʹ��� �Ÿ��� 450�̻��̶�� WALK2���·� ���� ��
		//�̹����� ó������ �����ϱ����� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) >= 450)
		{
			_state = E_WALK2;
			_index = 0;
		}
		//�÷��̾�� ���ʹ��� �Ÿ��� 450�̸��̰�
		if (getDistance(_x, _y, _pX, _pY) < 450)
		{
			//�÷��̾ ���ʹ��� �����ʿ��ִٸ�
			if (_x > _pX)
			{
				_left = true; //���ʹ̴� �������ٶ󺸰�
				if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� ���󰣴�
				{
					_x += 2.7f * cosf(getAngle(_x, _y, _pX + 90, _pY));
					_y -= 2.7f * sinf(getAngle(_x, _y, _pX + 90, _pY));
				}
			}
			else
			{
				_left = false; //���ʹ̴� �������� �ٶ󺸰�
				if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� ���󰣴�
				{
					_x += 2.7f * cosf(getAngle(_x, _y, _pX - 90, _pY));
					_y -= 2.7f * sinf(getAngle(_x, _y, _pX - 90, _pY));
				}
			}
		}
		break;

	case E_WALK2:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ε��� �ʱ�ȭ
		if (_index > 2) _index = 0;
		//�÷��̾�� ���ʹ��� �Ÿ��� 450�̸��̶�� WALK���·� ���� ��
		//������ �̹��� ���� ������ ���� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) < 450)
		{
			_state = E_WALK;
			_index = 0;
		}
		//�÷��̾ ���ʹ���
		if (_x > _pX) //�����ʿ� �ִٸ�
		{
			_left = true; //���ʹ̴� ������ �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� �̵��Ѵ�
			{
				_x += 4.f * cosf(getAngle(_x, _y, _pX + 100, _pY));
				_y -= 4.f * sinf(getAngle(_x, _y, _pX + 100, _pY));
			}
		}
		else //���ʿ� �ִٸ�
		{
			_left = false; //���ʹ̴� �������� �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� �̵��Ѵ�.
			{
				_x += 2.7f * cosf(getAngle(_x, _y, _pX - 100, _pY));
				_y -= 2.7f * sinf(getAngle(_x, _y, _pX - 100, _pY));
			}
		}
		break;

	case E_ATK:
		if (_index > 2)
		{
			_state = E_WALK;
			_index = 0;
		}
		break;

	case E_DEAD:
		if (_index > 3)
		{
			_index = 3;
		}
		break;

	case E_HIT:
		_index = 0;

		//�ǰݸ�� �����ð� (30 = 0.5��)
		//0.5�ʰ� ������ IDLE���·� �����
		if (_hitCount > 30)
		{
			_state = E_IDLE;
			_hitCount = 0;
		}
		if (_left) ++_x;
		else --_x;
		break;

	case E_GRAB:
		_index = 0;

		//�׷���� �����ð� (90 = 1.5��)
		//1.5�ʰ� ������ IDLE���·� �����
		if (_grabCount > 90)
		{
			_state = E_IDLE;
			_grabCount = 0;
		}
		break;

	case E_FLYING:
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ������ ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.right > CAMX + WINSIZEX && _flying && _left)
		{
			_flying = false;
			_index = 1;
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x -= 5;
		}
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ���� ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.left < CAMX && _flying && !_left)
		{
			_flying = false;
			_index = 1;
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x += 5;
		}
		//�ε����� ���������� �ʱ�ȭ�Ǿ��� �����ִ� ���¶�� �ö��׻��·� ���������
		if (!_flying && _index == 0) _flying = true;
		//�ö��� ���¿����� ��ǥ�� �̵���Ų��
		if (_flying && _left) _x += 15.5f;
		if (_flying && !_left) _x -= 15.5f;
		//�̹����� ���������� ���������� �����ȴٸ� IDLE���·� �����Ű�� �ε����� �ʱ�ȭ
		if (_index > 3)
		{
			_state = E_IDLE;
			_index = 0;
		}
		break;
	}
}

void boss::phase1() // ���ݷ�Ʈ�� ���ſ� ���ܼ� ġ��ٴ�
{
	if (getDistance(_x, _y, _destX, _destY) > 30)
	{
		_x += 10.f * cosf(getAngle(_x, _y, _destX, _destY));
		_y -= 10.f * sinf(getAngle(_x, _y, _destX, _destY));
	}
	else
	{
		++_rideCount;
		if (_rideCount > 120)
		{
			_rideCount = 0;
			_destX = _pX;
			_destY = _pY;
			if (_destX > _x) _left = false;
			else _left = true;
		}
	}
	if (_phaseCount > 600)
	{
		_phaseCount = 0; _phase = 0; _index = _rideCount = 0;
		_state = E_IDLE;
	}


	if (_index > 2)
	{
		_index = 0;
	}
}

void boss::phase2()
{ // �̶��� �׸��� ������ _destY���� �������ҵ�
	if (_jumping)
	{ // ������
		_y -= 20;
		if (_destY - _y > WINSIZEY)
		{
			_jumping = false;
			_x = _destX;
		}
	}
	else if (_destY > _y)
	{ // ����
		_y += 20;
	}
	else if (_destY <= _rc.bottom && !_jumping)
	{ // ������ ����ŷ
		_phaseCount = 0; _phase = 0; _index = _shakeCount = 0;
		_state = E_SHAKE;
		return;
	}

	if (_index > 2)
	{
		_index = 0;
	}
}


HRESULT boss::init(float x, float y)
{
	_x = CAMX + x;	_y = CAMY + y;
	_currentHP = _maxHP = 500.f;
	_count = _index = _attackCount = _hitCount = _grabCount = _phaseCount = _rideCount = 0;
	_state = E_IDLE;
	_phase = 0;
	_flying = _atkArea = _left = false;
	   
	_destX = _destY = 0;

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{	//������ ������ �Ǵ� �ӵ��� ��������
	_count++;
	if (_count % 10 == 0)
	{
		if (!_flying) _index++;
		_count = 0;
	}
	++_phaseCount;
	if (_phase == 0 ) bossState();
	else if (_phase == 1) phase1();
	else if (_phase == 2) phase2();

	_rc = RectMakeCenter(_x, _y, 200, 200);
}

void boss::render()
{
	Rectangle(getMemDC(), _rc);

	if (_phase == 0)
	{
		//�� ������ ���¿� ���� �����Ǵ� �̹����� ������
		switch (_state)
		{
		case E_SHAKE:
			if (_left) FINDIMG("boss_shakes")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_shakes")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_IDLE:
			if (_left) FINDIMG("boss_idle")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_idle")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_WALK:
			if (_left) FINDIMG("boss_walk")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_walk")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_WALK2:
			if (_left) FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left - 61, _rc.top, _index, 1);
			else FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left - 74, _rc.top, _index, 0);		break;
		case E_ATK:
			if (_left) FINDIMG("boss_atk")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_atk")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_DEAD:
			if (_left) FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_HIT:
			// _plAtkNum : �÷��̾� ���ݻ��� üũ�� �׽�Ʈ ����
			// 1 = �����ʿ��� �������� ���� , 2 = ���ʿ��� ���������� ����
			if (_plAtkNum == 1)
			{
				if (_left) FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
				else FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);
			}
			if (_plAtkNum == 2)
			{
				if (_left) FINDIMG("boss_hit2")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
				else FINDIMG("boss_hit2")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);
			}
			break;
		case E_GRAB:
			if (_left) FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0); break;
		case E_FLYING:
			if (_left) FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0); break;
		}
	}
	else if (_phase == 1)
	{
		if (_left) FINDIMG("boss_car")->frameRender(getMemDC(), _rc.left-75, _rc.top-90, _index, 1);
		else FINDIMG("boss_car")->frameRender(getMemDC(), _rc.left-136, _rc.top-90, _index, 0);
	}
	else if (_phase == 2)
	{
		if (_left) FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left-61, _rc.top, _index, 1);
		else FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left-74, _rc.top, _index, 0);
	}

}
