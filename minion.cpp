#include "stdafx.h"
#include "minion.h"

minion::minion()
{
}

minion::~minion()
{
}

void minion::enemyState()
{	
	_attackRc = { 0, 0, 0, 0 };
	_count++;
	//HIT���¿����� hitī��Ʈ�� ��������
	if (_state == E_HIT) _hitCount++;
	//GRAB���¿����� grabī��Ʈ�� ��������
	if (_state == E_GRAB) _grabCount++;
	//DEAD���¿��� ���߿� �ߴ� �ð��� üũ�ϱ����� ����
	if (_state == E_DEAD) _flyingCount++;

	//���ݹ��� �ȿ� �÷��̾ �ִ��� üũ��, �÷��̾�� ���ʹ��� ������ 100�̸��̸� true
	if (getDistance(_x, _y, _pX, _pY) < 100) _atkArea = true;
	//������ 100�̻��̸� false
	if (getDistance(_x, _y, _pX, _pY) >= 100) _atkArea = false;

	//������ ������ �Ǵ� �ӵ��� ��������
	if (_count % 10 == 0)
	{
		if(!_flying) _index++;
		_count = 0;
	}
		

	//���¸��� ����� ������
	switch (_state)
	{
	case E_IDLE:
		//������ �̹����� �ִ� �������� �ʰ����� �ʵ��� ��������
		if (_index > 2) _index = 0;
		
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
		break;

	case E_WALK:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ʱ�ȭ����
		if (_index > 2) _index = 0;
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
		}
		break;

	case E_WALK2:
		//������ �̹��� �ִ� �������� �ʰ������ʵ��� �ε��� �ʱ�ȭ
		if (_index > 9) _index = 0;
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
				_x += 2.7f * cosf(getAngle(_x, _y, _pX + 100, _pY + _randomNum));
				_y -= 2.7f * sinf(getAngle(_x, _y, _pX + 100, _pY + _randomNum));
			}
		}
		else //���ʿ� �ִٸ�
		{
			_left = false; //���ʹ̴� �������� �ٶ󺸰�
			if (!_atkArea) //�÷��̾��� �Ʒ���ǥ���� �̵��Ѵ�.
			{
				_x += 2.7f * cosf(getAngle(_x, _y, _pX - 100, _pY + _randomNum));
				_y -= 2.7f * sinf(getAngle(_x, _y, _pX - 100, _pY + _randomNum));
			}
		}
		break;

	case E_ATK:

		if (_index == 2)
		{
			if (_left)
			{
				_attackRc = RectMakeCenter(_x - 110, _y - 45, 80, 80);
			}
			else
			{
				_attackRc = RectMakeCenter(_x + 110, _y - 45, 80, 80);
			}
		}

		if (_index > 2)
		{
			_attackRc = RectMakeCenter(0, 0, 0, 0);
			setState(E_WALK);
		}
		break;

	case E_DEAD:
		_alpha -= 7;
		if (_alpha < 0) _alpha = 0;

		if (_index > 6)
		{
			_isDead = true;
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
			_x = _pX + 150;
			_y = _pY + 10;
		}
		else
		{
			_x = _pX - 150;
			_y = _pY + 10;
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
		if (_index > 3)
		{
			setState(E_IDLE);
		}
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
			setState(E_FLYING);
			_index = 1;
			_flyDown = false;
			_flying = false;
			if (_currentHP <= 0) setState(E_DEAD);
			getDamage(20);
		}
		if (_shadow.top - _rc.bottom > 400)
		{
			_flyDown = true;
		}
	}
}

void minion::enemyStateRender()
{
	//�� ������ ���¿� ���� �����Ǵ� �̹����� ������
	switch (_state)
	{
	case E_IDLE:
		if (_left) FINDIMG("enemy1_idle")->frameRender(getMemDC(), _rc.left - 40, _rc.top - 10, _index, 0);
		else FINDIMG("enemy1_idle")->frameRender(getMemDC(), _rc.left - 80, _rc.top - 10, _index, 1);		break;
	case E_WALK:
		if (_left) FINDIMG("enemy1_idle")->frameRender(getMemDC(), _rc.left - 40, _rc.top - 10, _index, 0);
		else FINDIMG("enemy1_idle")->frameRender(getMemDC(), _rc.left - 80, _rc.top - 10, _index, 1);		break;
	case E_WALK2:
		if (_left) FINDIMG("enemy1_walk")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 28, _index, 0);
		else FINDIMG("enemy1_walk")->frameRender(getMemDC(), _rc.left - 75, _rc.top - 28, _index, 1);		break;
	case E_ATK:
		if (_left) FINDIMG("enemy1_atk")->frameRender(getMemDC(), _rc.left - 130, _rc.top - 160, _index, 0);
		else FINDIMG("enemy1_atk")->frameRender(getMemDC(), _rc.left - 50, _rc.top - 160, _index, 1);		break;
	case E_DEAD:
		if (_left) FINDIMG("enemy1_dead")->alphaFrameRender(getMemDC(), _rc.left - 60, _rc.top - 30, _index, 0, _alpha);
		else FINDIMG("enemy1_dead")->alphaFrameRender(getMemDC(), _rc.left - 60, _rc.top - 30, _index, 1, _alpha);		break;
	case E_HIT:
		// _plAtkNum : �÷��̾� ���ݻ��� üũ�� �׽�Ʈ ����
		// 1 = �����ʿ��� �������� ���� , 2 = ���ʿ��� ���������� ����
		if (_plAtkNum == 1)
		{
			if (_left) FINDIMG("enemy1_hit1")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 43, _index, 0);
			else FINDIMG("enemy1_hit1")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 43, _index, 1);
		}
		if (_plAtkNum == 2)
		{
			if (_left) FINDIMG("enemy1_hit3")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 13, _index, 0);
			else FINDIMG("enemy1_hit3")->frameRender(getMemDC(), _rc.left - 65, _rc.top - 13, _index, 1);
		}
		break;
	case E_GRAB:
		if (_left) FINDIMG("enemy1_grab")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 30, _index, 0);
		else FINDIMG("enemy1_grab")->frameRender(getMemDC(), _rc.left, _rc.top - 30, _index, 1); break;
	case E_FLYING:
		if (_left) FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 10, _index, 0);
		else FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 10, _index, 1); break;
	case E_FLYING2:
		if (_left) FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left - 30, _rc.top - 10, _index, 0);
		else FINDIMG("enemy1_flying")->frameRender(getMemDC(), _rc.left - 60, _rc.top - 10, _index, 1); break;
	}
}

void minion::keyManager()
{
	//////////////////////////////////////////////////////////////////////
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _left = true;
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _left = false;
	if (KEYMANAGER->isOnceKeyDown(VK_F4)) { _plAtkNum += 1; if (_plAtkNum > 2) _plAtkNum = 1; }
	if (KEYMANAGER->isOnceKeyDown('1')) { setState(E_IDLE); }
	if (KEYMANAGER->isOnceKeyDown('2')) { setState(E_WALK);	}
	if (KEYMANAGER->isOnceKeyDown('3')) { setState(E_ATK);	}
	if (KEYMANAGER->isOnceKeyDown('4')) { setState(E_DEAD); }
	if (KEYMANAGER->isOnceKeyDown('5')) { setState(E_HIT);	}
	if (KEYMANAGER->isOnceKeyDown('6')) { setState(E_GRAB);	}
	if (KEYMANAGER->isOnceKeyDown('7')) { setState(E_FLYING);	}
	//////////////////////////////////////////////////////////////////////
}

HRESULT minion::init(float x, float y)
{
	_x = CAMX + x;	_y = CAMY + y;
	_currentHP = _maxHP = 100;
	_count = _index = _attackCount = _hitCount = _grabCount = _flyingCount = 0;
	setState(E_IDLE);
	_left = true;
	_plAtkNum = 1;
	_flying = false;
	_atkArea = false;
	_randomNum = RND->getFromIntTo(-3, 3);
	_isDead = false;
	_flyDown = false;
	_alpha = 255;
	return S_OK;
}

void minion::release()
{
}

void minion::update()
{
	_rc = RectMakeCenter(_x, _y, 150, 150);
	enemyState();
	//�׽�Ʈ��, ���� ��ġ������ �׻� �ּ�ó���Ұ�
	//keyManager();
	
	
	//���¿� ���� �׸����� ũ�⸦ �ٸ����Ͽ� �׷��ݴϴ�
	if(_state == E_IDLE || _state == E_WALK || _state == E_WALK2 || _state == E_ATK || _state == E_HIT) 
	_shadow = RectMakeCenter(_rc.left + 75, _rc.bottom + 10, 250, 50);

	if (_state == E_GRAB || _state == E_FLYING) _shadow = RectMakeCenter(_rc.left + 75, _rc.bottom + 10, 200, 50);
}

void minion::render()
{
	if(_state != E_DEAD) fillColorEllipse(40, 40, 40, _shadow);
	//Ellipse(getMemDC(), _shadow);

	enemyStateRender();
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc);
		Rectangle(getMemDC(), _attackRc);
	}
}