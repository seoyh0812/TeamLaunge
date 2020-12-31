#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}
void enemy::enemyAnim()
{
    _eCount++;

    if (_eCount % 10 == 0)
    {
        ++_eIndex;
        if (_eIndex > 2) _eIndex = 0;

        _eCount = 0;
    }
}

void enemy::enemyMove()
{
    _enemyPatCount++;

    if (_enemyPatCount >= 100)
    {
        _enemyPat = RND->getFromIntTo(0, 3);
        _enemyPatCount = 0;

        if (_enemyPat == 0) _enemyState = E_WORK_UP;
        if (_enemyPat == 1) _enemyState = E_WORK_L;
        if (_enemyPat == 2) _enemyState = E_WORK_R;
        if (_enemyPat == 3) _enemyState = E_WORK_DW;
    }


    if (_enemyState == E_WORK_UP)
    {
        if (_enemyPatCount >= 20)
        {
            _enemyRc.top -= 1;
            _enemyRc.bottom -= 1;
        }
    }
    if (_enemyState == E_WORK_L)
    {
        if (_enemyPatCount >= 20)
        {
            _enemyRc.left -= 1;
            _enemyRc.right -= 1;
        }
    }
    if (_enemyState == E_WORK_R)
    {
        if (_enemyPatCount >= 20)
        {
            _enemyRc.left += 1;
            _enemyRc.right += 1;
        }
    }
    if (_enemyState == E_WORK_DW)
    {
        if (_enemyPatCount >= 20)
        {
            _enemyRc.top += 1;
            _enemyRc.bottom += 1;
        }
    }

}

void enemy::onDis()
{
    if (_enemyHp <= 0) _disappear = true;
}




HRESULT enemy::init()
{
    return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
    IMAGEMANAGER->addFrameImage("enemy", "image/enemy_idle.bmp", 240, 60, 4, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("eWork", "image/enemy_work.bmp", 180, 240, 3, 4, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("eAtk", "image/enemy_atk.bmp", 240, 240, 4, 4, true, RGB(255, 0, 255));

    // _eIndex = RND->getFromIntTo(0, 3);
    _eCount = _enemyPat = 0;
    _enemyState = E_WORK_DW;
    _disappear = false;

    _enemy = IMAGEMANAGER->findImage(imageName);

    _enemyRc = RectMakeCenter(position.x, position.y, _enemy->getFrameWidth(), _enemy->getFrameHeight());

    _enemyHp = _enemyMaxHp = 100;

    _enemyHpBar = new progressBar2;
    _enemyHpBar->init2(_enemyRc.left - 30, _enemyRc.top - 5, 60, 8);
    _enemyHpBar->setGauge2(_enemyHp, _enemyMaxHp);

    _enemyPatCount = 0;

    return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
    enemyAnim();
    enemyMove();
    onDis();

    _enemyHpBar->setX2(_enemyRc.left);
    _enemyHpBar->setY2(_enemyRc.top - 5);
    _enemyHpBar->setGauge2(_enemyHp, _enemyMaxHp);
    _enemyHpBar->update();

}

void enemy::render()
{
    /*_enemy->frameRender(getMemDC(), _enemyRc.left, _enemyRc.top);
    _enemyHpBar->render();
    if (KEYMANAGER->isToggleKey(VK_F1))
    {
       Rectangle(getMemDC(), _enemyRc.left, _enemyRc.top, _enemyRc.right, _enemyRc.bottom);
    }*/
}

void enemy::render(int x, int y)
{
    //_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
    if (KEYMANAGER->isToggleKey(VK_F1))
    {
        Rectangle(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _enemyRc.right - x, _enemyRc.bottom - y);
    }


    switch (_enemyState)
    {
    case E_IDLE_UP:
        IMAGEMANAGER->findImage("enemy")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, 3, 0);
        break;
    case E_IDLE_L:
        IMAGEMANAGER->findImage("enemy")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, 1, 0);
        break;
    case E_IDLE_R:
        IMAGEMANAGER->findImage("enemy")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, 2, 0);
        break;
    case E_IDLE_DW:
        IMAGEMANAGER->findImage("enemy")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, 0, 0);
        break;
    case E_WORK_UP:
        IMAGEMANAGER->findImage("eWork")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _eIndex, 3);
        break;
    case E_WORK_L:
        IMAGEMANAGER->findImage("eWork")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _eIndex, 1);
        break;
    case E_WORK_R:
        IMAGEMANAGER->findImage("eWork")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _eIndex, 2);
        break;
    case E_WORK_DW:
        IMAGEMANAGER->findImage("eWork")->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _eIndex, 0);
        break;

    }
    _enemyHpBar->render(x, y);
}


//#include "stdafx.h"
//#include "enemy.h"
//
//enemy::enemy()
//{
//}
//
//enemy::~enemy()
//{
//}
//void enemy::enemyAnim()
//{
//	_eCount++;
//
//	if (_eCount % 10 == 0)
//	{
//		switch (_enemyState)
//		{
//		case E_IDLE_UP:
//			//_enemy = IMAGEMANAGER->addImage("enemy", 240, 60);
//			_eIndex = 3;
//			_enemy->setFrameY(0);
//			_enemy->setFrameX(_eIndex);
//			break;
//
//		case E_IDLE_L:
//			//_enemy = IMAGEMANAGER->addImage("enemy", 240, 60);
//			_eIndex = 1;
//			_enemy->setFrameY(0);
//			_enemy->setFrameX(_eIndex);
//			break;
//
//		case E_IDLE_R:
//			//_enemy = IMAGEMANAGER->addImage("enemy", 240, 60);
//			_eIndex = 2;
//			_enemy->setFrameY(0);
//			_enemy->setFrameX(_eIndex);
//			break;
//
//		case E_IDLE_DW:
//			//_enemy = IMAGEMANAGER->addImage("enemy", 240, 60);
//			_eIndex = 0;
//			_enemy->setFrameY(0);
//			_enemy->setFrameX(_eIndex);
//			break;
//
//		case E_WORK_UP:
//			//_enemy = IMAGEMANAGER->addImage("eWork", 180, 240);
//			if (_eIndex >= 3)
//			{
//				_enemyState = E_IDLE_UP;
//				_eIndex = 0;
//			}
//			_enemy->setFrameY(3);
//			_enemy->setFrameX(_eIndex);
//			_eIndex++;
//			break;
//
//		case E_WORK_L:
//			//_enemy = IMAGEMANAGER->addImage("eWork", 180, 240);
//			if (_eIndex >= 3)
//			{
//				_enemyState = E_IDLE_L;
//				_eIndex = 0;
//			}
//			_enemy->setFrameY(1);
//			_enemy->setFrameX(_eIndex);
//			_eIndex++;
//			break;
//
//		case E_WORK_R:
//			//_enemy = IMAGEMANAGER->addImage("eWork", 180, 240);
//			if (_eIndex >= 3)
//			{
//				_enemyState = E_IDLE_R;
//				_eIndex = 0;
//			}
//			_enemy->setFrameY(2);
//			_enemy->setFrameX(_eIndex);
//			_eIndex++;
//			break;
//
//		case E_WORK_DW:
//			//_enemy = IMAGEMANAGER->addImage("eWork", 180, 240);
//			if (_eIndex >= 3)
//			{
//				_enemyState = E_IDLE_DW;
//				_eIndex = 0;
//			}
//			_enemy->setFrameY(0);
//			_enemy->setFrameX(_eIndex);
//			_eIndex++;
//			break;
//
//		}
//
//		_eCount = 0;
//	}
//}
//
//void enemy::enemyMove()
//{
//	_enemyPatCount++;
//
//	if (_enemyPatCount >= 100)
//	{
//		_enemyPat = RND->getFromIntTo(0, 4);
//		_enemyPatCount = 0;
//	}
//
//	if (_enemyPat == 0) _enemyState = E_WORK_UP;
//	else if (_enemyPat == 1) _enemyState = E_WORK_L;
//	else if (_enemyPat == 2) _enemyState = E_WORK_R;
//	else if (_enemyPat == 3) _enemyState = E_WORK_DW;
//
//	if (_enemyState == E_WORK_UP)
//	{
//		if (_enemyPatCount >= 30)
//		{
//			_enemyRc.top -= 1;
//			_enemyRc.bottom -= 1;
//		}
//	}
//	if (_enemyState == E_WORK_L)
//	{
//		if (_enemyPatCount >= 30)
//		{
//			_enemyRc.left -= 1;
//			_enemyRc.right -= 1;
//		}
//	}
//	if (_enemyState == E_WORK_R)
//	{
//		if (_enemyPatCount >= 30)
//		{
//			_enemyRc.left += 1;
//			_enemyRc.right += 1;
//		}
//	}
//	if (_enemyState == E_WORK_DW)
//	{
//		if (_enemyPatCount >= 30)
//		{
//			_enemyRc.top += 1;
//			_enemyRc.bottom += 1;
//		}
//	}
//
//}
//
//
//
//
//HRESULT enemy::init()
//{
//	return S_OK;
//}
//
//HRESULT enemy::init(const char* imageName, POINT position)
//{
//	IMAGEMANAGER->addFrameImage("enemy", "image/enemy_idle.bmp", 240, 60, 4, 1, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addFrameImage("eWork", "image/enemy_work.bmp", 180, 240, 3, 4, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addFrameImage("eAtk", "image/enemy_atk.bmp", 240, 240, 4, 4, true, RGB(255, 0, 255));
//
//	_eIndex = RND->getFromIntTo(0,3);
//	_eCount = _enemyPat = 0;
//	_enemyState = E_WORK_DW;
//
//	_enemy = IMAGEMANAGER->findImage(imageName);
//
//	_enemyRc = RectMakeCenter(position.x, position.y, _enemy->getFrameWidth(), _enemy->getFrameHeight());
//
//	_enemyHp = _enemyMaxHp = 100;
//
//	_enemyHpBar = new progressBar2;
//	_enemyHpBar->init2(_enemyRc.left - 30, _enemyRc.top - 5, 60, 8);
//	_enemyHpBar->setGauge2(_enemyHp, _enemyMaxHp);
//
//	_enemyPatCount = 0;
//
//	return S_OK;
//}
//
//void enemy::release()
//{
//}
//
//void enemy::update()
//{
//	enemyAnim();
//	enemyMove();
//
//	_enemyHpBar->setX2(_enemyRc.left);
//	_enemyHpBar->setY2(_enemyRc.top - 5);
//	_enemyHpBar->setGauge2(_enemyHp, _enemyMaxHp);
//	_enemyHpBar->update();
//
//}
//
//void enemy::render()
//{
//	/*_enemy->frameRender(getMemDC(), _enemyRc.left, _enemyRc.top);
//	_enemyHpBar->render();
//	if (KEYMANAGER->isToggleKey(VK_F1))
//	{
//		Rectangle(getMemDC(), _enemyRc.left, _enemyRc.top, _enemyRc.right, _enemyRc.bottom);
//	}*/
//}
//
//void enemy::render(int x, int y)
//{
//	//switch (_enemyState)
//	//{
//	//	case E_WORK_UP:
//	//		
//	//		_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
//	//		break;
//
//	//	case E_WORK_L:
//	//		_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
//	//		break;
//
//	//	case E_WORK_R:
//	//		_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
//	//		break;
//
//	//	case E_WORK_DW:
//	//		_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
//	//		break;
//	//}
//
//	_enemy->frameRender(getMemDC(), _enemyRc.left - x, _enemyRc.top - y);
//	_enemyHpBar->render(x , y);
//	if (KEYMANAGER->isToggleKey(VK_F1))
//	{
//		Rectangle(getMemDC(), _enemyRc.left - x, _enemyRc.top - y, _enemyRc.right - x, _enemyRc.bottom - y);
//	}
//}

