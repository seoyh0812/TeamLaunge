#include "stdafx.h"
#include "titleScene.h"

titleScene::titleScene()
{
}

titleScene::~titleScene()
{
}

HRESULT titleScene::init()
{
	CAMERAMANAGER->setCameraX(0);
	CAMERAMANAGER->setCameraY(0);



	return S_OK;
}

void titleScene::release()
{
}

void titleScene::update()
{
}

void titleScene::render()
{
}
