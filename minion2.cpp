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
	_attackRc = { 0, 0, 0, 0 };
	_count++;
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
	//������ ������ �Ǵ� �ӵ��� ��������
	if (_count % 10 == 0)
	{
		_index++;
		_count = 0;
	}

	switch (_state)
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
			if ((getDistance(_x, _y, _pX, _pY) > 200)) setState(E_WALK);
			else
			{
				_attackCount++;
				if (_attackCount > 45)
				{
					setState(E_ATK);
					_attackCount = 0;
				}
			}
			_index = 0;
		}
		else
		{
			//������ �����ʵ� ����
			_left = false;
			if ((getDistance(_x, _y, _pX, _pY) > 200)) setState(E_WALK);
			else
			{
				_attackCount++;
				if (_attackCount > 45)
				{
					setState(E_ATK);
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
				setState(E_ATK);
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
		
		if (_left)
		{
			_attackRc = RectMakeCenter(_x - 90, _y - 40, 140, 60);
		}
		else
		{
			_attackRc = RectMakeCenter(_x + 90, _y - 40, 140, 60);
		}

		if (_index > 15)
		{
			_attackRc = RectMakeCenter(0, 0, 0, 0);
			setState(E_IDLE);
		}

		break;

	case E_DEAD:
		_alpha -= 7;
		_index = 0;
		if (_deadCount > 30)
		{
			_isDead = true;
			_deadCount = 0;
		}
		break;

	case E_HIT:
		_index = 0;
		if (_left) _x += 0.8f;
		else _x -= 0.8f;
		//�ǰݸ�� �����ð� (30 = 0.5��)
		if (_hitCount > 30)
		{
			setState(E_IDLE);
			_hitCount = 0;
		}

		if (_currentHP <= 0)
		{
			setState(E_DEAD);
		}
		break;

	case E_GRAB:
		_index = 0;

		if (_left)
		{
			_x = _pX + 150;
			_y = _pY + 10;
		}
		else
		{
			_x = _pX - 150;
			_y = _pY + 10;
		}

		//�׷���� �����ð� (90 = 1.5��)
		if (_grabCount > 90)
		{
			setState(E_IDLE);
			_grabCount = 0;
		}
		break;

	case E_FLYING:
		//�����ִ»��¿��� �ε����� ����������
		if (_flying) _index = 0;

		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ������ ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.right > CAMX + WINSIZEX && _flying && _left)
		{
			//if (_currentHP <= 0) setState(E_DEAD);
			//else _currentHP -= 20;

			//_flying = false;
			//_index = 1;
			setState(E_FLYING2);
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x -= 5;
		}
		//���� ��Ʈ�� ����Ʈ�� ī�޶� ȭ�� ���� ������ ���������Ѵٸ� ü�����¸� Ǯ�� �ε����� 1�� �ٲ۴�
		if (_rc.left < CAMX && _flying && !_left && _index == 0)
		{
			//if (_currentHP <= 0) setState(E_DEAD);
			//else _currentHP -= 20;

			//_flying = false;
			//_index = 1;
			setState(E_FLYING2);
			//x��ǥ ��ġ�� �������ִ� ������ �����ָ� �ְ� ���� ����
			_x += 5;
		}
		//�ε����� ���������� �ʱ�ȭ�Ǿ��� �����ִ� ���¶�� �ö��׻��·� ���������
		if (!_flying && _index == 0) _flying = true;
		//�ö��� ���¿����� ��ǥ�� �̵���Ų��
		if (_flying && _left) _x += 15.5f;
		if (_flying && !_left) _x -= 15.5f;
		//�̹����� ���������� ���������� �����ȴٸ� IDLE���·� �����Ű�� �ε����� �ʱ�ȭ
		break;

	case E_FLYING2:
		if (_flying) _index = 0;

		if (!_flyDown)
		{
			if (_shadow.left != _shadow.right)
			{
				_shadow.left += 1;
				_shadow.right -= 1;
			}
		}
		if (_flyDown && _left && _shadow.left != _shadow.right)
		{
			_shadow.left -= 6;
			_shadow.right -= 6;
		}
		if (_flyDown && !_left && _shadow.left != _shadow.right)
		{
			_shadow.left += 6;
			_shadow.right += 6;
		}
		if (_left && !_flyDown)
		{
			_y -= 25.0f;
			_x -= 5.5f;
		}
		else if (_left && _flyDown)
		{
			_y += 25.0f;
			_x -= 5.5f;
		}
		else if (!_left && !_flyDown)
		{
			_y -= 25.0f;
			_x += 5.5f;
		}
		else
		{
			_y += 25.0f;
			_x += 5.5f;
		}
		if (_flyDown && _rc.bottom >= _shadow.top - 10)
		{
			setState(E_IDLE);
			//_index = 1;
			_flyDown = false;
			_flying = false;
			getDamage(20);
			if (_currentHP <= 0) setState(E_DEAD);
		}
		if (_shadow.top - _rc.bottom > 400)
		{
			_flyDown = true;
		}
	}
}

void minion2::enemyStateRender()
{
	switch (_state)
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
		if (_left) FINDIMG("enemy2_dead")->alphaFrameRender(getMemDC(), _rc.left - 110, _rc.top - 175, _index, 1, _alpha);
		else FINDIMG("enemy2_dead")->alphaFrameRender(getMemDC(), _rc.left - 60, _rc.top - 175, _index, 0, _alpha);		break;
	case E_HIT:
		if (_left) FINDIMG("enemy2_hit")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 77, _index, 0);
		else FINDIMG("enemy2_hit")->frameRender(getMemDC(), _rc.left - 175, _rc.top - 87, _index, 1);		break;
	case E_GRAB:
		if (_left) FINDIMG("enemy2_grab")->frameRender(getMemDC(), _rc.left - 180, _rc.top - 100, _index, 0);
		else FINDIMG("enemy2_grab")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 100, _index, 1);		break;
	case E_FLYING:
		if (_left) FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 77, _index, 0);
		else FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 220, _rc.top - 77, _index, 1);	break;
	case E_FLYING2:
		if (_left) FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 10, _index, 0);
		else FINDIMG("enemy2_flying")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 10, _index, 1); break;
	}
}

void minion2::keyManager()
{
	//////////////////////////////////////////////////////////////////////
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _left = true;
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _left = false;
	if (KEYMANAGER->isOnceKeyDown('1')) { _index = 0; _state = E_IDLE; }
	if (KEYMANAGER->isOnceKeyDown('2')) { _index = 0; _state = E_WALK; }
	if (KEYMANAGER->isOnceKeyDown('3')) { _index = 0; _state = E_ATK; }
	if (KEYMANAGER->isOnceKeyDown('4')) { _index = 0; _state = E_DEAD; }
	if (KEYMANAGER->isOnceKeyDown('5')) { _index = 0; _state = E_HIT; }
	if (KEYMANAGER->isOnceKeyDown('6')) { _index = 0; _state = E_GRAB; }
	if (KEYMANAGER->isOnceKeyDown('7')) { _index = 0; _state = E_FLYING; }
	//////////////////////////////////////////////////////////////////////
}

HRESULT minion2::init(float x, float y)
{
	_x = CAMX + x;	_y = CAMY + y;
	_currentHP = _maxHP = 100;
	_count = _index = _attackCount = _hitCount = _grabCount = _deadCount = 0;
	setState(E_IDLE);
	_left = true;
	_flying = false;
	_atkArea = false;
	_randomNum = RND->getFromIntTo(20, 50);
	_isDead = false;
	_flyDown = false;
	_alpha = 255;
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
	if (_state == E_IDLE || _state == E_WALK || _state == E_WALK2 || _state == E_ATK || _state == E_HIT)
		_shadow = RectMakeCenter(_rc.left + 25, _rc.bottom + 10, 200, 50);

	if (_state == E_GRAB || _state == E_FLYING) _shadow = RectMakeCenter(_rc.left + 25, _rc.bottom + 10, 150, 50);
}

void minion2::render()
{
	if(_state != E_DEAD) fillColorEllipse(40, 40, 40, _shadow);
	enemyStateRender();
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc);
		Rectangle(getMemDC(), _attackRc);
	}
}

