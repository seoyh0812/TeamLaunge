#include "stdafx.h"
#include "mainScene.h"

void mainScene::cameraControl()
{
	RECT temp = _pl->getGroundRc();
	CAMERAMANAGER->focusOnRect(temp, 3, 3);

	if (CAMY < 700) // 루프렌더용
	{
		_loopRc = RectMake(2122, 0, 4691, 428);
		_loopX += 8;
		_loopY += 0; // 이것도 위치에따라바꾸면 좋을거같음
	}
}