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
	_loopX = 0;	_loopY = 300; _loopCount = 0;
	_mapChanging = false;
	CAMERAMANAGER->setCameraY(MAPSIZEY-WINSIZEY);
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
	cameraControl();
}

void mainScene::render()
{
	//FINDIMG("��")->render(getMemDC()); //�̷��Ծ��� �� ������(�ּ�Ǯ�� �غ����� �غ���)
	if (CAMY < 700) FINDIMG("â�����")->loopRender(getMemDC(), &_loopRc, _loopX, _loopY);
	FINDIMG("��")->render(getMemDC(), CAMX, CAMY,CAMX,CAMY,WINSIZEX,WINSIZEY); // Ư���κи� �������
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		TIMEMANAGER->render(getMemDC(),CAMX,CAMY);
	}
	_pl->render();
	_cl->render(); // �ٸ� ���͵��� z���� �Լ����� �׸��� �Ǿ� ����.

	zOrderRender();
	if (CAMX > 2060-WINSIZEX && CAMX < 2133)FINDIMG("���")->render(getMemDC(), 2060, 1536);
	
}