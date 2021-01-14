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
	//DEAD���¿����� deadī��Ʈ�� ��������
	if (_state == E_DEAD) _deadCount++;

	//���ݹ��� �ȿ� �÷��̾ �ִ��� üũ��, �÷��̾�� ���ʹ��� ������ 100�̸��̸� true
	if (getDistance(_x, _y, _pX, _pY) < 100) _atkArea = true;
	//������ 100�̻��̸� false
	if (getDistance(_x, _y, _pX, _pY) >= 100) _atkArea = false;


	if (_phaseCount > 300 && _state != E_GRAB && _state != E_DEAD && _state != E_HIT
		&& _state != E_FLYING && _currentHP > 0) // ������ �ٲ�
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
			if (_shakeCount > 2)
			{
				setState(E_WALK);
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
				setState(E_WALK);
			}
			else
			{
				//������ �����ʵ� ����
				_left = false;
				setState(E_WALK);
			}
		}
		else
		{
			_attackCount++;
			if (_attackCount > 45)
			{
				setState(E_ATK);
				_attackCount = 0;
			}
		}

		break;

	case E_WALK:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ʱ�ȭ����
		if (_index > 3) _index = 0;

		if (_destX > _x) _left = false;
		else _left = true;
		//�÷��̾�� ���ʹ��� �Ÿ��� 200���϶�� ATK���·� ���� ��
		//�̹����� ó������ �����ϱ����� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) <= 200)
		{
			_attackCount++;
			if (_attackCount > 45)
			{
				setState(E_ATK);
				_attackCount = 0;
			}
		}
		//�÷��̾�� ���ʹ��� �Ÿ��� 450�̻��̶�� WALK2���·� ���� ��
		//�̹����� ó������ �����ϱ����� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) >= 450)
		{
			setState(E_WALK2);
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
					_x += 4.f * cosf(getAngle(_x, _y, _pX + 90, _pY));
					_y -= 4.f * sinf(getAngle(_x, _y, _pX + 90, _pY));
				}
			}
			else
			{
				_left = false; //���ʹ̴� �������� �ٶ󺸰�
				if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� ���󰣴�
				{
					_x += 4.f * cosf(getAngle(_x, _y, _pX - 90, _pY));
					_y -= 4.f * sinf(getAngle(_x, _y, _pX - 90, _pY));
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
			setState(E_WALK);
		}
		//�÷��̾ ���ʹ���
		if (_x > _pX) //�����ʿ� �ִٸ�
		{
			_left = true; //���ʹ̴� ������ �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� �̵��Ѵ�
			{
				_x += 8.f * cosf(getAngle(_x, _y, _pX + 100, _pY));
				_y -= 8.f * sinf(getAngle(_x, _y, _pX + 100, _pY));
			}
		}
		else //���ʿ� �ִٸ�
		{
			_left = false; //���ʹ̴� �������� �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� �̵��Ѵ�.
			{
				_x += 8.f * cosf(getAngle(_x, _y, _pX - 100, _pY));
				_y -= 8.f * sinf(getAngle(_x, _y, _pX - 100, _pY));
			}
		}
		break;

	case E_ATK:
		if (_index == 2)
		{
			if (_left)
			{
				_attackRc = RectMakeCenter(_x - 110, _y - 45, 120, 80);
			}
			else
			{
				_attackRc = RectMakeCenter(_x + 110, _y - 45, 120, 80);
			}
		}
		if (_index > 2)
		{
			_attackRc = RectMakeCenter(0, 0, 0, 0);
			setState(E_IDLE);
		}
		break;

	case E_DEAD:
		if (_index >= 3)
		{
			_index = 3;
		}
		else
		{
			if (_left) _x += 2;
			else _x -= 2;
		}
		break;

	case E_HIT:
		_index = 0;
		if (_left) _x += 0.8f;
		else _x -= 0.8f;

		if (_currentHP <= 0)
		{
			setState(E_DEAD);
		}

		//�ǰݸ�� �����ð� (30 = 0.5��)
		//0.5�ʰ� ������ IDLE���·� �����
		if (_hitCount > 30 && _currentHP > 0)
		{
			setState(E_IDLE);
			_hitCount = 0;
		}
		break;

	case E_GRAB:
		_index = 0;

		if (_left)
		{
			_x = _pX + 120;
			_y = _pY;
		}
		else
		{
			_x = _pX - 120;
			_y = _pY;
		}

		break;

	case E_FLYING:
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ������ ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_flying) _index = 0;

		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ������ ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.right > CAMX + WINSIZEX && _flying && _left)
		{
			if (_currentHP <= 0) setState(E_DEAD);
			else _currentHP -= 20;

			_flying = false;
			_index = 1;
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x -= 5;
		}
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ���� ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.left < CAMX && _flying && !_left)
		{
			if (_currentHP <= 0) setState(E_DEAD);
			else _currentHP -= 20;

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
			setState(E_IDLE);
		}
		break;
	}
}

void boss::phase1() // ���ݷ�Ʈ�� ���ſ� ���ܼ� ġ��ٴ�
{
	_state = E_HIT;
	if (getDistance(_x, _y, _destX, _destY) > 30)
	{
		_x += 10.f * cosf(getAngle(_x, _y, _destX, _destY));
		_y -= 10.f * sinf(getAngle(_x, _y, _destX, _destY));
		_attackRc = RectMakeCenter(_x, _y+100, 300, 100);
	}
	else
	{
		_attackRc = { 0,0,0,0 };
		++_rideCount;
		if (_rideCount > 80)
		{
			_rideCount = 0;
			_destX = _pX;
			_destY = _pY;
			if (_destX > _x) _left = false;
			else _left = true;
		}
	}
	if (_phaseCount > 300)
	{
		_phaseCount = 0; _phase = 0; _index = _rideCount = 0;
		_state = E_IDLE;
		_attackRc = { 0,0,0,0 };
	}


	if (_index > 2)
	{
		_index = 0;
	}
}

void boss::phase2()
{ 
	_state = E_HIT;
	if (_jumping)
	{ // ������
		_attackRc = { 0,0,0,0 };
		_y -= 20;
		if (_destY - _y > WINSIZEY)
		{
			_destY = _pY+60;
			_destX = _pX;
			_x = _destX;
			_jumping = false;
		}
	}
	else if (_destY > _rc.bottom)
	{ // ����
		_attackRc = RectMakeCenter(_x, _y + 70, 180, 60);
		_y += 20;
	}
	else if (_destY <= _rc.bottom)
	{ // ������ ����ŷ
		_phaseCount = _phase = _shakeCount = 0;
		setState(E_SHAKE);
		_attackRc = { 0,0,0,0 };
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
	_phase = 1;
	_plAtkNum = 1;
	_flying = _atkArea = false;
	_left = true;
	_destX = CAMX + WINSIZEY / 2;
	_destY = CAMY + WINSIZEY / 2;

	SOUNDMANAGER->stop("���κ��");
	SOUNDMANAGER->play("��������");
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{	//������ ������ �Ǵ� �ӵ��� ��������
	_attackRc = { 0,0,0,0 };
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
	//���¿� ���� �׸����� ũ�⸦ �ٸ����Ͽ� �׷��ݴϴ�
	if (_phase == 0)
	{
		switch (_state)
		{
		case E_IDLE: case E_WALK: case E_ATK: case E_HIT: case E_GRAB:
			_rc = RectMakeCenter(_x, _y, 150, 200);
			_shadow = RectMakeCenter(_rc.left + 75, _rc.bottom + 10, 150, 50);
			break;
		case E_DEAD: case E_FLYING:
			_rc = RectMakeCenter(_x, _y, 208, 200);
			_shadow = RectMakeCenter(_rc.left + 104, _rc.bottom - 20, 208, 50);
			break;
		case E_SHAKE:		case E_WALK2:
			_rc = RectMakeCenter(_x, _y+40, 180, 120);
			_shadow = RectMakeCenter(_rc.left + 90, _rc.bottom + 10, 180, 50);
			break;
		}
	}	
	if (_phase == 1)
	{ // ������
		_rc = RectMakeCenter(_x, _y, 200, 200);
		_shadow = RectMakeCenter(_rc.left + 100, _rc.bottom + 50, 350, 70);
	}
	if (_phase == 2)
	{
		_rc = RectMakeCenter(_x, _y, 180, 120);
		if (_jumping)
		{
			_shadow = RectMake(_shadow.left, _shadow.top, 180, 50);
		}
		else  _shadow = RectMakeCenter(_destX, _destY+60, 180, 50);
	}
	if(!SOUNDMANAGER->isPlaySound("��������") && 
		!SOUNDMANAGER->isPlaySound("�������") &&
		!SOUNDMANAGER->isPlaySound("���κ��"))
	{//���� ����.
		SOUNDMANAGER->play("������Ҹ�");
		SOUNDMANAGER->play("�������");
	}
}

void boss::render()
{
	fillColorEllipse(40, 40, 40, _shadow);
	if (_phase == 0)
	{
		//�� ������ ���¿� ���� �����Ǵ� �̹����� ������
		switch (_state)
		{
		case E_SHAKE:
			if (_left) FINDIMG("boss_shakes")->frameRender(getMemDC(), _rc.left-20, _rc.top-15, _index, 1);
			else FINDIMG("boss_shakes")->frameRender(getMemDC(), _rc.left-30, _rc.top-15, _index, 0);		break;
		case E_IDLE:
			if (_left) FINDIMG("boss_idle")->frameRender(getMemDC(), _rc.left-48, _rc.top, _index, 1);
			else FINDIMG("boss_idle")->frameRender(getMemDC(), _rc.left-20, _rc.top, _index, 0);		break;
		case E_WALK:
			if (_left) FINDIMG("boss_walk")->frameRender(getMemDC(), _rc.left-15, _rc.top, _index, 1);
			else FINDIMG("boss_walk")->frameRender(getMemDC(), _rc.left-25, _rc.top, _index, 0);		break;
		case E_WALK2:
			if (_left) FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left-21, _rc.top-5, _index, 1);
			else FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left-40, _rc.top-5, _index, 0);		break;
		case E_ATK:
			if (_left) FINDIMG("boss_atk")->frameRender(getMemDC(), _rc.left-120, _rc.top, _index, 1);
			else FINDIMG("boss_atk")->frameRender(getMemDC(), _rc.left-45, _rc.top, _index, 0);		break;
		case E_DEAD:
			if (_left) FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0);		break;
		case E_HIT:
			// _plAtkNum : �÷��̾� ���ݻ��� üũ�� �׽�Ʈ ����
			// 1 = �����ʿ��� �������� ���� , 2 = ���ʿ��� ���������� ����
			if (_plAtkNum == 1)
			{
				if (_left) FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left - 33, _rc.top, 0, 1);
				else FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left - 3, _rc.top, 0, 0);	break;
			}
			if (_plAtkNum == 2)
			{
				if (_left) FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left - 33, _rc.top, 0, 1);
				else FINDIMG("boss_hit4")->frameRender(getMemDC(), _rc.left - 3, _rc.top, 0, 0);	break;
			}
		case E_GRAB:

			if (_plAtkNum == 1)
			{
				if (_left) FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left - 5, _rc.top, 0, 1);
				else FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left - 3, _rc.top, 0, 0); break;
			}
			if (_plAtkNum == 2)
			{
				if (_left) FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left - 5, _rc.top, 0, 1);
				else FINDIMG("boss_hit")->frameRender(getMemDC(), _rc.left - 3, _rc.top, 0, 0); break;
			}
		case E_FLYING:
			if (_left) FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 1);
			else FINDIMG("boss_dead")->frameRender(getMemDC(), _rc.left, _rc.top, _index, 0); break;
		}
	}
	else if (_phase == 1)
	{
		if (_left) FINDIMG("boss_car")->frameRender(getMemDC(), _rc.left-100, _rc.top-50, _index, 1);
		else FINDIMG("boss_car")->frameRender(getMemDC(), _rc.left-100, _rc.top-50, _index, 0);
	}
	else if (_phase == 2)
	{
		if (_left) FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left - 21, _rc.top-5, _index, 1);
		else FINDIMG("boss_crawl")->frameRender(getMemDC(), _rc.left - 40, _rc.top - 5, _index, 0);
	}
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc);
		Rectangle(getMemDC(), _attackRc);
	}
	
}
