#include "stdafx.h"
#include "minion2.h"

minion2::minion2()
{
}

minion2::~minion2()
{
}

void minion2::enemyState()
{
	_count++;
	//HIT���¿����� hitī��Ʈ�� ��������
	if (_state2 == E_HIT) _hitCount++;
	//GRAB���¿����� grabī��Ʈ�� ��������
	if (_state2 == E_GRAB) _grabCount++;

	//���ݹ��� �ȿ� �÷��̾ �ִ��� üũ��, �÷��̾�� ���ʹ��� ������ 100�̸��̸� true
	if (getDistance(_x, _y, _pX, _pY) < 100) _atkArea = true;
	//������ 100�̻��̸� false
	if (getDistance(_x, _y, _pX, _pY) >= 100) _atkArea = false;
	//������ ������ �Ǵ� �ӵ��� ��������
	if (_count % 10 == 0)
	{
		_index++;
		_count = 0;
	}

	switch (_state2)
	{
	case E_IDLE:
		//������ �̹����� �ִ� �������� �ʰ����� �ʵ��� ��������
		if (_index > 1) _index = 0;

		//�÷��̾ ���ʹ��� �����ʿ� �ִٸ�
		if (_x > _pX)
		{
			//���ʹ̴� ������ �����ִٰ� �������ְ� WALK���·� ���� �� 
			//�ִϸ��̼��� ó������ ó���ϱ����� �ε����� 0���� �ʱ�ȭ
			_left = true;
			if ((getDistance(_x, _y, _pX, _pY) > 200)) _state2 = E_WALK;
			else
			{
				_attackCount++;
				if (_attackCount > 45)
				{
					_state2 = E_ATK;
					_index = 0;
					_attackCount = 0;
				}
			}
			_index = 0;
		}
		else
		{
			//������ �����ʵ� ����
			_left = false;
			if ((getDistance(_x, _y, _pX, _pY) > 200)) _state2 = E_WALK;
			else
			{
				_attackCount++;
				if (_attackCount > 45)
				{
					_state2 = E_ATK;
					_index = 0;
					_attackCount = 0;
				}
			}
			_index = 0;
		}
		break;

	case E_WALK:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ʱ�ȭ����
		if (_index > 4) _index = 0;
		//�÷��̾�� ���ʹ��� �Ÿ��� 200���϶�� ATK���·� ���� ��
		//�̹����� ó������ �����ϱ����� �ε��� �ʱ�ȭ
		if (getDistance(_x, _y, _pX, _pY) <= 200)
		{
			_attackCount++;
			if (_attackCount > 45)
			{
				_state2 = E_ATK;
				_index = 0;
				_attackCount = 0;
			}
		}
			//�÷��̾ ���ʹ��� �����ʿ��ִٸ�
		if (_x > _pX)
		{
			_left = true; //���ʹ̴� �������ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� ���󰣴�
			{
				_x += 2.7f * cosf(getAngle(_x, _y, _pX + 90, _pY + _randomNum));
				_y -= 2.7f * sinf(getAngle(_x, _y, _pX + 90, _pY + _randomNum));
			}
		}
		else
		{
			_left = false; //���ʹ̴� �������� �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� ���󰣴�
			{
				_x += 2.7f * cosf(getAngle(_x, _y, _pX - 90, _pY + _randomNum));
				_y -= 2.7f * sinf(getAngle(_x, _y, _pX - 90, _pY + _randomNum));
			}
		}
		break;

	case E_ATK:
		if (_index > 15)
		{
			_state2 = E_IDLE;
			_index = 0;
		}
		break;

	case E_DEAD:
		_index = 0;
		break;

	case E_HIT:
		_index = 0;
		//�ǰݸ�� �����ð� (30 = 0.5��)
		if (_hitCount > 30)
		{
			_state2 = E_IDLE;
			_hitCount = 0;
		}
		break;

	case E_GRAB:
		_index = 0;
		//�׷���� �����ð� (90 = 1.5��)
		if (_grabCount > 90)
		{
			_state2 = E_IDLE;
			_grabCount = 0;
		}
		break;

	case E_FLYING:
		_index = 0;
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ������ ������ ���������Ѵٸ� ü�����¸� Ǯ�� IDLE ���·� ����
		if (_rc.right > CAMX + WINSIZEX && _flying && _left)
		{
			_flying = false;
			_state2 = E_IDLE;
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x -= 5;
		}
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ���� ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.left < CAMX && _flying && !_left)
		{
			_flying = false;
			_state2 = E_IDLE;
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x += 5;
		}
		//�ε����� ���������� �ʱ�ȭ�Ǿ��� �����ִ� ���¶�� �ö��� ���·� ���������
		if (!_flying) _flying = true;
		//�ö��� ���¿����� ��ǥ�� �̵���Ų��
		if (_flying && _left) _x += 15.5f;
		if (_flying && !_left) _x -= 15.5f;

		break;
	}
}

void minion2::enemyStateRender()
{
	switch (_state2)
	{
	case E_IDLE:
		if (_left) FINDIMG("enemy2_idle")->frameRender(getMemDC(), _rc.left - 70, _rc.top - 160, _index, 1);
		else FINDIMG("enemy2_idle")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 160, _index, 0);		break;
	case E_WALK:
		if (_left) FINDIMG("enemy2_move")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 160, _index, 1);
		else FINDIMG("enemy2_move")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 160, _index, 0);		break;
	case E_ATK:
		if (_left) FINDIMG("enemy2_atk")->frameRender(getMemDC(), _rc.left - 253, _rc.top - 172, _index, 1);
		else FINDIMG("enemy2_atk")->frameRender(getMemDC(), _rc.left - 158, _rc.top - 172, _index, 0);		break;
	case E_DEAD:
		if (_left) FINDIMG("enemy2_dead")->frameRender(getMemDC(), _rc.left - 110, _rc.top - 175, _index, 1);
		else FINDIMG("enemy2_dead")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 175, _index, 0);		break;
	case E_HIT:
		if (_left) FINDIMG("enemy2_hit")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 77, _index, 0);
		else FINDIMG("enemy2_hit")->frameRender(getMemDC(), _rc.left - 175, _rc.top - 87, _index, 1);		break;
	case E_GRAB:
		if (_left) FINDIMG("enemy2_grab")->frameRender(getMemDC(), _rc.left - 180, _rc.top - 100, _index, 0);
		else FINDIMG("enemy2_grab")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 100, _index, 1);		break;
	case E_FLYING:
		if (_left) FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 77, _index, 0);
		else FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 220, _rc.top - 77, _index, 1);	break;
	}
}

void minion2::keyManager()
{
	//////////////////////////////////////////////////////////////////////
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _left = true;
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _left = false;
	if (KEYMANAGER->isOnceKeyDown('1')) { _index = 0; _state2 = E_IDLE; }
	if (KEYMANAGER->isOnceKeyDown('2')) { _index = 0; _state2 = E_WALK; }
	if (KEYMANAGER->isOnceKeyDown('3')) { _index = 0; _state2 = E_ATK; }
	if (KEYMANAGER->isOnceKeyDown('4')) { _index = 0; _state2 = E_DEAD; }
	if (KEYMANAGER->isOnceKeyDown('5')) { _index = 0; _state2 = E_HIT; }
	if (KEYMANAGER->isOnceKeyDown('6')) { _index = 0; _state2 = E_GRAB; }
	if (KEYMANAGER->isOnceKeyDown('7')) { _index = 0; _state2 = E_FLYING; }
	//////////////////////////////////////////////////////////////////////
}

HRESULT minion2::init(float x, float y)
{
	_x = CAMX + x;	_y = CAMY + y;
	_currentHP = _maxHP = 100;
	_count = _index = _attackCount = _hitCount = _grabCount = 0;
	_state2 = E_IDLE;
	_left = true;
	_flying = false;
	return S_OK;
}

void minion2::release()
{
}

void minion2::update()
{
	_rc = RectMakeCenter(_x, _y, 50, 200);
	enemyState();
	//�׽�Ʈ��, ���� ��ġ������ �׻� �ּ�ó���Ұ�
	//keyManager();

	//���¿� ���� �׸����� ũ�⸦ �ٸ����Ͽ� �׷��ݴϴ�
	if (_state2 == E_IDLE || _state2 == E_WALK || _state2 == E_WALK2 || _state2 == E_ATK || _state2 == E_DEAD || _state2 == E_HIT)
		_shadow = RectMakeCenter(_rc.left + 25, _rc.bottom + 10, 200, 50);

	if (_state2 == E_GRAB || _state2 == E_FLYING) _shadow = RectMakeCenter(_rc.left + 25, _rc.bottom + 10, 150, 50);
}

void minion2::render()
{
	fillColorEllipse(40, 40, 40, _shadow);
	enemyStateRender();
	if (KEYMANAGER->isToggleKey(VK_F1)) Rectangle(getMemDC(), _rc);
}

