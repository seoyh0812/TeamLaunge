#include "stdafx.h"
#include "player.h"
#include "STATE.h"
#include "Idle.h"
#include "Jump.h"
#include "walk.h"
#include "run.h"
#include "combo1.h"
#include "enemyManager.h"
// �� ����� �ƴϳĸ� ��ȣ����(��ӹް�) ���� �ֱ� �����̶�� ��
// �߰��ҋ� �������� ���⿡�� �߰�

player::player()
{
}

player::~player()
{
}

HRESULT player::init()
{
	_flyX = _groundX = 100.f;
	_flyY = _groundY = CAMY + 300.f;
	_directionChanged = _directionChangeCount = _dirMemory = _dirMemoryCount = 0;
	_flyRc = RectMakeCenter(_flyX, _flyY, 50, 50);
	_groundRc = RectMakeCenter(_groundX, _groundY, 20, 20);
	_currentHP = _maxHP = 100.f;
	_left = false;
	setState(IDLE);
	_attack = new attack;
	_attack->init(3, 50);
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
	_flyRc = RectMakeCenter(_flyX, _flyY, 50, 50);
	_groundRc = RectMakeCenter(_groundX, _groundY, 50, 50);	
	minusDirectionChanged();
	_attack->update(50);
}

void player::render()
{
	switch (_enumState)
	{
	case IDLE: sprintf_s(_str, "IDLE");		break;
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
	Rectangle(getMemDC(), _groundRc);
	Rectangle(getMemDC(), _flyRc);
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
	}
	_statePattern->LinkMemberAdress(this);
	// �����Ҷ����� �÷��̱׶��忡�� ��ũ���״��� ���ݾ�?
	// ���⼱ �ٷ� �̰� �� ������ �ϴ°ž�
	// ������� idle���� _pl->setState(~~)�� �ϴµ�
	// _pl�� �� Ŭ����(this)�� �����ϵ��� �ϴ°ž�
	// (�ƴϸ� �׳� �󲮵���)
	_statePattern->EnterState();
}
