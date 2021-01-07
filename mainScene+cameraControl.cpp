#include "stdafx.h"
#include "mainScene.h"

void mainScene::cameraControl()
{
	RECT temp = _pl->getGroundRc();
	//if (_em->getVEnemy().size() == 0) CAMERAMANAGER->cameraLockOff();
	//else CAMERAMANAGER->cameraLock(); // ���� ������ ķ����, ���� ������ ķ���� ǯ
	CAMERAMANAGER->focusOnRect(temp, 3);
	if (CAMY <= 55 && CAMX < 1849) CAMERAMANAGER->setCameraX(1849);
	if (CAMY > 55 && CAMX > 2816) CAMERAMANAGER->setCameraX(2816);
	if (CAMY != 55 && CAMX == 2816) _mapChanging = true;

	if (_mapChanging && CAMY > 55)
	{
		CAMERAMANAGER->setCameraY(CAMY-20);
		// _pl->setState(); // �̵��� ������Ʈ�� �־ �̵������ϸ� �ɵ�
		_pl->getGroundY() -= 20;
		_pl->getFlyY() -= 20;
		if (CAMY < 55)
		{
			CAMERAMANAGER->setCameraY(55);
			_mapChanging = false;
		}
	}
	if (CAMY < 700) // ����������
	{
		_loopRc = RectMake(2040, 55, 4691, 500);
		_loopX += 10;
		if (_loopX >= 1024) _loopX -= 1024;
		if (_loopCount < 6 && _loopY > 0) ++_loopCount;
		if (_loopCount >= 6)
		{
			_loopCount = 0;
			--_loopY;
		}
	}
}

