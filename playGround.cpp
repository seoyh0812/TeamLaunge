#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);
	srand(time(NULL));
	imageInit();
	SCENEMANAGER->addScene("���ξ�", new mainScene);
	SCENEMANAGER->addScene("Ÿ��Ʋ��", new titleScene);
	SCENEMANAGER->addScene("������", new endingScene);

	SCENEMANAGER->changeScene("���ξ�");
	
	return S_OK;
}


void playGround::release()
{
	gameNode::release();

	SCENEMANAGER->release();
}

void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();	
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ ���� �ǵ��� ���� ==============================
	
	//IMAGEMANAGER->findImage("�����")->render(getMemDC());	
	
	SCENEMANAGER->render();

	
	//================= �Ʒ��� �ǵ��� ���� ==============================
	_backBuffer->render(getHDC(), 0, 0, CAMX, CAMY, WINSIZEX, WINSIZEY);
}

