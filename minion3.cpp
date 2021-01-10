#include "stdafx.h"
#include "minion3.h"


minion3::minion3()
{
}


minion3::~minion3()
{
}

void minion3::enemyState()
{// �����������

 //�� ���� ������ ����
	_count++;
	if (_state == E_HIT) _hitCount++;
	if (_state == E_GRAB) _grabCount++;
	if (_state == E_FLYING) _flyingCount++;

	if (_count % 10 == 0)
	{
		if (!_flying) _index++;
		_count = 0;
	}

	switch (_state3)

	{

	case E_IDLE: // �ָ������� �̵�	
	//������ ���¿� ���� �̹��� �ε��� ũ�Ⱑ �ٸ��Ƿ� ���� ��������
		if (_index > 1) _index = 0;
		//if (getDistance(_x, _y, _pX, _pY) > 80)
		//{
		//	if (_x > _pX)
		//	{
		//		_left = true;
		//		_state = E_WALK;
		//		_index = 0; // ��ȯ���ְ� �ε��� �ʱ�ȭ
		//	}
		//	else
		//	{
		//		_left = false;
		//		_state = E_WALK;
		//		_index = 0; // ��ȯ���ְ� �ε��� �ʱ�ȭ
		//	}
		//}
		//else // ������ ������ ��ٷȴ� ���ݸ��
		//{
		//	++_attackCount;
		//	if (_attackCount > 60)
		//	{
		//		_attackCount = 0;
		//		_state = E_ATK;
		//		_index = 0;
		//	}
		//}
		break;

	case E_WALK:
		if (_index > 4) _index = 0;
		/*if (getDistance(_x, _y, _pX, _pY) > 80)
		{
			if (_x > _pX)
			{
				_left = true;
				_x += 2.f * cosf(getAngle(_x, _y, _pX + 30, _pY));
				_y -= 2.f * sinf(getAngle(_x, _y, _pX + 30, _pY));
			}
			else
			{
				_left = false;
				_x += 2.f * cosf(getAngle(_x, _y, _pX - 30, _pY));
				_y -= 2.f * sinf(getAngle(_x, _y, _pX - 30, _pY));
			}
		}
		else
		{
			_state = E_IDLE;
			_index = 0;
		}*/
		break;

	case E_ATK:
		if (_index > 2)
		{
			_state = E_IDLE;
			_index = 0;
		}
		break;

	case E_DEAD:
		if (_index > 3) _index = 0;
		break;

	case E_HIT:
		// _plAtkNum : �÷��̾� ���ݻ��� üũ�� �׽�Ʈ ����
		// 1 = �����ʿ��� �������� ���� , 2 = ���ʿ��� ���������� ����
		_index = 0;

		//�ǰݸ�� �����ð� (30 = 0.5��)
		if (_hitCount > 30)
		{
			_state = E_IDLE;
			_hitCount = 0;
		}
		break;

		case E_GRAB:
			_index = 0;

			//�׷���� �����ð� (90 = 1.5��)
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
			//�׸��� �ö��� ���¿����� ��ǥ�� �̵���Ű�� ���� �� �� ���ϰ� ������ �ʿ���
			if (!_flying && _index == 0) _flying = true;
			if (_flying && _left) _x += 15.5f;
			if (_flying && !_left) _x -= 15.5f;


			if (_index > 3)
			{
				_state = E_IDLE;
				_index = 0;
			}
			break;
	}
}

void minion3::enemyStateRender()
{
	//�� ������ ���¿� ���� �����Ǵ� �̹����� ������
	switch (_state3)
	{
	case E_IDLE:
		if (_left) FINDIMG("enemy3_idle")->frameRender(getMemDC(), _rc.left - 40, _rc.top - 10, _index, 0);
		else FINDIMG("enemy3_idle")->frameRender(getMemDC(), _rc.left - 80, _rc.top - 10, _index, 1);		break;
	case E_WALK:
		if (_left) FINDIMG("enemy3_walk")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 28, _index, 0);
		else FINDIMG("enemy3_walk")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 28, _index, 1);		break;
	case E_ATK:
		if (_left) FINDIMG("enemy3_atk")->frameRender(getMemDC(), _rc.left - 130, _rc.top - 160, _index, 0);
		else FINDIMG("enemy3_atk")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 160, _index, 1);		break;
	case E_DEAD:
		if (_left) FINDIMG("enemy3_dead")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 30, _index, 0);
		else FINDIMG("enemy3_dead")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 30, _index, 1);		break;
	case E_HIT:
		if (_left) FINDIMG("enemy3_hit")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 43, _index, 0);
		else FINDIMG("enemy3_hit")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 43, _index, 1);		break;
	case E_GRAB:
		if (_left) FINDIMG("enemy3_grab")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 30, _index, 0);
		else FINDIMG("enemy3_grab")->frameRender(getMemDC(), _rc.left, _rc.top - 30, _index, 1); break;
	case E_FLYING:
		if (_left) FINDIMG("enemy3_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 10, _index, 0);
		else FINDIMG("enemy3_flying")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 10, _index, 1); break;
	}
}

void minion3::keyManager()
{
	//////////////////////////////////////////////////////////////////////
	if (KEYMANAGER->isToggleKey(VK_F1)) Rectangle(getMemDC(), _rc);
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _left = true;
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _left = false;
	if (KEYMANAGER->isOnceKeyDown('1')) { _index = 0; _state3 = E_IDLE; }
	if (KEYMANAGER->isOnceKeyDown('2')) { _index = 0; _state3 = E_WALK; }
	if (KEYMANAGER->isOnceKeyDown('3')) { _index = 0; _state3 = E_ATK; }
	if (KEYMANAGER->isOnceKeyDown('4')) { _index = 0; _state3 = E_DEAD; }
	if (KEYMANAGER->isOnceKeyDown('5')) { _index = 0; _state3 = E_HIT; }
	if (KEYMANAGER->isOnceKeyDown('6')) { _index = 0; _state3 = E_GRAB; }
	if (KEYMANAGER->isOnceKeyDown('7')) { _index = 0; _state3 = E_FLYING; }
	//////////////////////////////////////////////////////////////////////
}
HRESULT minion3::init(float x, float y)
{
	_x = CAMX + x;	_y = CAMY + y;
	_currentHP = _maxHP = 100;
	_count = _index = _attackCount = _hitCount = _grabCount = _flyingCount = 0;
	_state3 = E_IDLE;
	_left = true;
	_flying = false;
	return S_OK;
}

void minion3::release()
{
}

void minion3::update()
{
	_rc = RectMakeCenter(_x, _y, 150, 150);
	enemyState();
}

void minion3::render()
{
	enemyStateRender();


	//�׽�Ʈ��, ���� ��ġ������ �׻� �ּ�ó���Ұ�
	keyManager();
}


