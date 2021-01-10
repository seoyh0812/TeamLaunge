#include "stdafx.h"
#include "minion3.h"


minion3::minion3()
{
}


minion3::~minion3()
{
}

void minion3::enemyState()
{// 유사상태패턴

 //볼 몬스터 프레임 렌더
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

	case E_IDLE: // 멀리있으면 이동	
	//몬스터의 상태에 따라 이미지 인덱스 크기가 다르므로 각각 지정해줌
		if (_index > 1) _index = 0;
		//if (getDistance(_x, _y, _pX, _pY) > 80)
		//{
		//	if (_x > _pX)
		//	{
		//		_left = true;
		//		_state = E_WALK;
		//		_index = 0; // 전환해주고 인덱스 초기화
		//	}
		//	else
		//	{
		//		_left = false;
		//		_state = E_WALK;
		//		_index = 0; // 전환해주고 인덱스 초기화
		//	}
		//}
		//else // 가까이 있으면 기다렸다 공격모션
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
		// _plAtkNum : 플레이어 공격상태 체크용 테스트 변수
		// 1 = 오른쪽에서 왼쪽으로 공격 , 2 = 왼쪽에서 오른쪽으로 공격
		_index = 0;

		//피격모션 유지시간 (30 = 0.5초)
		if (_hitCount > 30)
		{
			_state = E_IDLE;
			_hitCount = 0;
		}
		break;

		case E_GRAB:
			_index = 0;

			//그랩모션 유지시간 (90 = 1.5초)
			if (_grabCount > 90)
			{
				_state = E_IDLE;
				_grabCount = 0;
			}
			break;

		case E_FLYING:
			//몬스터 렉트의 라이트가 카메라 화면 오른쪽 밖으로 나가려고한다면 체공상태를 풀고 인덱스를 1로 바꾼다
			if (_rc.right > CAMX + WINSIZEX && _flying && _left)
			{
				_flying = false;
				_index = 1;
				//x좌표 위치를 보정해주는 이유는 안해주면 애가 가끔 낑김
				_x -= 5;
			}
			//몬스터 렉트의 레프트가 카메라 화면 왼쪽 밖으로 나가려고한다면 체공상태를 풀고 인덱스를 1로 바꾼다
			if (_rc.left < CAMX && _flying && !_left)
			{
				_flying = false;
				_index = 1;
				//x좌표 위치를 보정해주는 이유는 안해주면 애가 가끔 낑김
				_x += 5;
			}
			//인덱스가 정상적으로 초기화되었고 지상에있는 상태라면 플라잉상태로 변경시켜줌
			//그리고 플라잉 상태에서만 좌표를 이동시키며 아직 좀 더 상세하게 수정이 필요함
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
	//볼 몬스터의 상태에 따라 렌더되는 이미지를 정해줌
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


	//테스트용, 파일 합치기전엔 항상 주석처리할것
	keyManager();
}


