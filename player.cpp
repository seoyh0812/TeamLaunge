#include "stdafx.h"
#include "player.h"
#include "STATE.h"
#include "Idle.h"
#include "Jump.h"
#include "walk.h"
#include "run.h"
#include "combo1.h"
#include "combo11.h"
#include "combo12.h"
#include "combo13.h"
#include "combo21.h"
#include "combo22.h"
#include "combo23.h"
#include "jumpAttack.h"
#include "tackle.h"
#include "slide.h"
#include "enemyManager.h"
// �� ����� �ƴϳĸ� ��ȣ����(��ӹް�) ���� �ֱ� �����̶�� ��
// �߰��ҋ� �������� ���⿡�� �߰�

HRESULT player::init()
{
	playerImage = IMAGEMANAGER->findImage("�÷��̾���");
	_count = _index = 0;
	_flyX = _groundX = 100.f;
	_flyY = _groundY = CAMY + 300.f;
	_directionChanged = _directionChangeCount = _dirMemory = _dirMemoryCount = 0;
	_flyRc = RectMakeCenter(_flyX, _flyY, playerImage->getFrameWidth() / 4, playerImage->getFrameHeight());
	_groundRc = RectMakeCenter(_groundX, _groundY, playerImage->getFrameWidth() / 4, playerImage->getFrameHeight());
	_currentHP = _maxHP = 100.f;
    _jumpPower = 15;
	_left = false;
	setState(IDLE);
	_attack = new attack;
	_attack->init(8, 50);
	//setState(IDLE);
	_em = new enemyManager;
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_statePattern->updateState();
	stateUpdate();
	_flyRc = RectMakeCenter(_flyX, _flyY, playerImage->getFrameWidth() / 4, playerImage->getFrameHeight());
	_groundRc = RectMakeCenter(_groundX, _groundY, playerImage->getFrameWidth() / 4, playerImage->getFrameHeight());
	minusDirectionChanged();
	_attack->update(50);
}

void player::render()
{
	/*
	switch (_enumState)
	{
	case IDLE: IMAGEMANAGER->findImage("�÷��̾���")->frameRender(getMemDC(), _flyRc.left, _flyRc.top);	break;
	case JUMP: sprintf_s(_str, "JUMP");		break;
	case WALK: sprintf_s(_str, "WALK");		break;
	case RUN: sprintf_s(_str, "RUN");		break;
	}
	TextOut(getMemDC(), 0, 60, _str, strlen(_str));
	if (_left > 0) sprintf_s(_str, "LEFT");
	else if (_left == 0) sprintf_s(_str, "RIGHT");
	TextOut(getMemDC(), 60, 60, _str, strlen(_str));
	if (_directionChanged >= 2)
	{ // ������ 0.5�ʳ� �ι� �ٲ���� == �¿�(or����)�Է��� �� ������
		sprintf_s(_str, "�̶� ��ư�� ������ Ư����� �������� ����");
		TextOut(getMemDC(), 0, 80, _str, strlen(_str));
	}
	*/ // �����
	_attack->render();
}

void player::minusDirectionChanged()
{
	if (_directionChanged > 0) // ������ȯ�� �Ͼ�ٸ�
	{
		if (_directionChanged > 2) _directionChanged = 2; // ������ȯ 2�� ������ 2������ ���ְ�
		++_directionChangeCount; // ī��Ʈ����
		if (_directionChangeCount > 30) // 30(0.5��) �̻� �����ٸ�
		{
			_directionChangeCount = 0; // ī��Ʈ 0���� ������
			--_directionChanged; // ������ȯ �ٿ���
		}
	} // ���� : ������ȯ �� �� �Ͼ ��� Ư��Ű ����������� ��

	if (_dirMemory > 0) // ���� ���Ǿ� �ִٸ�
	{
		++_dirMemoryCount;
		if (_dirMemoryCount > 30)
		{ // 30(0.5��)ī��Ʈ���� �ʱ�ȭ ������
			_dirMemoryCount = 0;
			_dirMemory = 0;
		}
	}
}

void player::playerRender()
{	
	stateRender();
	if(KEYMANAGER->isToggleKey(VK_TAB))
	{ 
		Rectangle(getMemDC(), _groundRc);
		Rectangle(getMemDC(), _flyRc);
	}
}

//���¼���

void player::setState(State state)
{
	if (_statePattern)_statePattern->ExitState();
	// ���� ������ exitState()�Լ��� ȣ��
	_enumState = state;
	switch (state)
	{ // ������Ʈ�� �ٲٰ� �׿��°� ���°�ü�� ����� ����̾�
	case IDLE:	_statePattern = new Idle;	break;
	case JUMP:	_statePattern = new Jump;	break;
	case WALK:	_statePattern = new walk;	break;
	case RUN:	_statePattern = new run;	break;
	case COMBO1: _statePattern = new combo1; break;
	case COMBO11: _statePattern = new combo11; break;
	case COMBO12: _statePattern = new combo12; break;
	case COMBO13: _statePattern = new combo13; break;
    case COMBO21: _statePattern = new combo21; break;
    case COMBO22: _statePattern = new combo22; break;
    case COMBO23: _statePattern = new combo23; break;
    case JUMPATTACK: _statePattern = new jumpAttack; break;
    case SLIDE: _statePattern = new slide; break;
    case TACKLE: _statePattern = new tackle; break;
	}
	_statePattern->LinkMemberAdress(this);
	// �����Ҷ����� �÷��̱׶��忡�� ��ũ���״��� ���ݾ�?
	// ���⼱ �ٷ� �̰� �� ������ �ϴ°ž�
	// ������� idle���� _pl->setState(~~)�� �ϴµ�
	// _pl�� �� Ŭ����(this)�� �����ϵ��� �ϴ°ž�
	// (�ƴϸ� �׳� �󲮵���)
	_statePattern->EnterState();

}

//���¿� ���� �̹����� ã�� ������ִ� �Լ�
void player::stateUpdate()
{
	_count++;
	if (_count % 5 == 0)
	{
		switch (_enumState)
		{
		case IDLE:
			playerImage = IMAGEMANAGER->findImage("�÷��̾���");
			if (!_left) { playerImage->setFrameY(0); }
			else { playerImage->setFrameY(1); }
			playerImage->setFrameX(0);
			break;
		case JUMP:
			playerImage = IMAGEMANAGER->findImage("�÷��̾�����");
			if (!_left) { playerImage->setFrameY(0); }
			else { playerImage->setFrameY(1); }
			playerImage->setFrameX(0);
			break;
		case WALK:
			playerImage = IMAGEMANAGER->findImage("�÷��̾��̵�");
			if (!_left)
			{
				if (_index >= 5) _index = 0;
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index <= 0) _index = 5;
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index--;
			}
			break;
		case RUN:
			playerImage = IMAGEMANAGER->findImage("�÷��̾���");
			if (!_left)
			{
				if (_index >= 3) _index = 0;
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index <= 0) _index = 3;
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index--;
			}
			break;
		case COMBO1:
			playerImage = IMAGEMANAGER->findImage("�÷��̾����");
			if (!_left)
			{
				if (_index >= 9) setState(IDLE);
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index >= 9) setState(IDLE);
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index++;
			}
			break;
		case COMBO11:
			playerImage = IMAGEMANAGER->findImage("�÷��̾����1-1");
			if (!_left)
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index++;
			}
			break;
		case COMBO12:
			playerImage = IMAGEMANAGER->findImage("�÷��̾����1-2");
			if (!_left)
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index++;
			}
			break;
		case COMBO13:
			playerImage = IMAGEMANAGER->findImage("�÷��̾����1-3");
			if (!_left)
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index >= 6) setState(IDLE);
				playerImage->setFrameY(1);
				playerImage->setFrameX(_index);
				_index++;
			}
			break;
        case COMBO21:
            playerImage = IMAGEMANAGER->findImage("�÷��̾����2-1");
            if (!_left)
            {
                if (_index >= 6) setState(IDLE);
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
                _index++;
            }
            else
            {
                if (_index >= 6) setState(IDLE);
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
                _index++;
            }
            break;
        case COMBO22:
            playerImage = IMAGEMANAGER->findImage("�÷��̾����2-2");
            if (!_left)
            {
                if (_index >= 6) setState(IDLE);
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
                _index++;
            }
            else
            {
                if (_index >= 6) setState(IDLE);
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
                _index++;
            }
            break;
        case COMBO23:
            playerImage = IMAGEMANAGER->findImage("�÷��̾����2-3");
            if (!_left)
            {
                if (_index >= 9) setState(IDLE);
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
                _index++;
            }
            else
            {
                if (_index >= 9) setState(IDLE);
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
                _index++;
            }
            break;
        case SLIDE:
            playerImage = IMAGEMANAGER->findImage("�÷��̾���̵�"); // �����̵��� ��Ŭ�� ���� �Ÿ� �̵��ϸ� ���������ʿ��� �����·� �ٲ�� ��������.
            if (!_left)
            {
                _index = 0;
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
            }
            else
            {
                _index = 0;
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
            }
            break;
        case TACKLE:
            playerImage = IMAGEMANAGER->findImage("�÷��̾���Ŭ");
            if (!_left)
            {
                _index = 0;
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
            }
            else
            {
                _index = 0;
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
            }
            break;
        case JUMPATTACK:
            playerImage = IMAGEMANAGER->findImage("�÷��̾���������");
            if (!_left)
            {
                if (_index >= 6) setState(JUMP);
                playerImage->setFrameY(0);
                playerImage->setFrameX(_index);
                _index++;
            }
            else
            {
                if (_index >= 6) setState(JUMP);
                playerImage->setFrameY(1);
                playerImage->setFrameX(_index);
                _index++;
            }
            break;
		case GRAB:
			playerImage = IMAGEMANAGER->findImage("�÷��̾����");
			if (!_left)
			{
				if (_index >= 1) _index = 0;
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
			else
			{
				if (_index >= 1) _index = 0;
				playerImage->setFrameY(0);
				playerImage->setFrameX(_index);
				_index++;
			}
		}
		_count = 0;
	}
	
}



// ���¿� ���� �̹��� ��ġ�� �������ְ� �������ִ� �Լ� 
void player::stateRender() 
{

	switch (_enumState)
	{
	case IDLE:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 123, _flyRc.top);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 67, _flyRc.top);
		break;
	case JUMP:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 75, _flyRc.top - 12);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 100, _flyRc.top - 12);
		break;
	case WALK:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 115, _flyRc.top - 12);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 77, _flyRc.top - 12);
		break;
	case RUN:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 100, _flyRc.top - 3);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 40, _flyRc.top - 3);
		break;
	case COMBO1:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 62, _flyRc.top + 18);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 164, _flyRc.top + 18);
		break;
	case COMBO11:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 60, _flyRc.top + 9);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 120, _flyRc.top + 9);
		break;
	case COMBO12:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 120, _flyRc.top - 39);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 150, _flyRc.top - 39);
		break;
	case COMBO13:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 60, _flyRc.top - 10);
		else playerImage->frameRender(getMemDC(), _flyRc.left - 180, _flyRc.top - 10);
		break;
    case COMBO21:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 90, _flyRc.top - 18);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 150, _flyRc.top - 18);
        break;
    case COMBO22:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 120, _flyRc.top);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 150, _flyRc.top);
        break;
    case COMBO23:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 60, _flyRc.top + 12);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 180, _flyRc.top + 12);
        break;
    case SLIDE:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 60, _flyRc.top);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 120, _flyRc.top);
        break;
    case TACKLE:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 120, _flyRc.top);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 30, _flyRc.top);
        break;
    case JUMPATTACK:
        if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left - 60, _flyRc.top - 12);
        else playerImage->frameRender(getMemDC(), _flyRc.left - 180, _flyRc.top - 12);
        break;
	case GRAB:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left, _flyRc.top);
		else playerImage->frameRender(getMemDC(), _flyRc.left, _flyRc.top);
		break;
	case GRABSWING:
		if (!_left) playerImage->frameRender(getMemDC(), _flyRc.left, _flyRc.top);
		else playerImage->frameRender(getMemDC(), _flyRc.left, _flyRc.top);
		break;
	}
}
