#include "stdafx.h"
#include "mainScene.h"

void mainScene::cameraControl()
{
	RECT temp = _pl->getGroundRc();
	//if (_em->getVEnemy().size() == 0) CAMERAMANAGER->cameraLockOff();
	//else CAMERAMANAGER->cameraLock(); // 적이 있으면 캠고정, 적이 없으면 캠고정 풂
	CAMERAMANAGER->focusOnRect(temp, 3);
	if (CAMY <= 0 && CAMX < 1849) CAMERAMANAGER->setCameraX(1849);
	if (CAMY > 0 && CAMX > 2816) CAMERAMANAGER->setCameraX(2816);
	//1852, 3844
	if (CAMY != 0 && CAMX == 2816) _mapChanging = true;

	if (_mapChanging && CAMY > 0)
	{
		CAMERAMANAGER->setCameraY(CAMY-20);
		// _pl->setState(); // 이동중 스테이트를 넣어서 이동봉쇄하면 될듯
		_pl->getGroundY() -= 20;
		_pl->getFlyY() -= 20;
		if (CAMY < 0)
		{
			CAMERAMANAGER->setCameraY(0);
			_mapChanging = false;
		}
	}
	if (CAMY < 700) // 루프렌더용
	{
		_loopRc = RectMake(2122, 0, 4691, 428);
		_loopX += 10;
		if (_loopX >= 1024) _loopX -= 1024;
		_loopY += 0; // 이것도 위치에따라바꾸면 좋을거같음
	}
}