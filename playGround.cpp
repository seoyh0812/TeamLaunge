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
	SCENEMANAGER->addScene("������", new videoScene);

	SCENEMANAGER->changeScene("������");
	_videoPlaying = true;
	
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

	if (KEYMANAGER->isStayKeyDown(VK_RETURN) && _videoPlaying)
	{
		_videoPlaying = false;
		SCENEMANAGER->changeScene("���ξ�");
	}

	SCENEMANAGER->update();	
}


void playGround::render()
{
	if (!_videoPlaying) PatBlt(getMemDC(), 0, 0, CAMX+WINSIZEX, CAMY+WINSIZEY, WHITENESS);
	//================ ���� �ǵ��� ���� ==============================
	
	SCENEMANAGER->render();
	
	//================= �Ʒ��� �ǵ��� ���� ==============================
	if (!_videoPlaying) _backBuffer->render(getHDC(), 0, 0, CAMX, CAMY, WINSIZEX, WINSIZEY);
}

