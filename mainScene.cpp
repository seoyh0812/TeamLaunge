#include "stdafx.h"
#include "mainScene.h"

mainScene::mainScene()
{
}

mainScene::~mainScene()
{
}

HRESULT mainScene::init()
{
	CAMERAMANAGER->setCameraX(0);
	CAMERAMANAGER->setCameraY(0);
	_pl = new player;		_pl->init();
	_em = new enemyManager;	_em->init();
	_sm = new stageManager; _sm->init();
	_im = new itemManager;	_im->init();
	_cl = new collision;	_cl->init();

	_cl->setPlMemoryAddressLink(_pl);
	_cl->setEmMemoryAddressLink(_em);
	_cl->setSmMemoryAddressLink(_sm);
	_cl->setImMemoryAddressLink(_im);

	return S_OK;
}

void mainScene::release()
{
	_cl->release();
	_pl->release();
	_em->release();
	_sm->release();
	_im->release();
}

void mainScene::update()
{
	_pl->update();
	_em->update();
	_sm->update();
	_im->update();
	_cl->update();
}

void mainScene::render()
{

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		TIMEMANAGER->render(getMemDC());
	}
	_pl->render();
	_em->render();
	_sm->render();
	_im->render();
	_cl->render();

	zOrderRender();
	
}