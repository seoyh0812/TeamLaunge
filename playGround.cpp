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
	soundInit();
	imageInitChanho(); imageInitDeokho(); imageInitHyunjeong(); imageInitYoongho(); imageInitYounghan();
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

	if (_videoPlaying)
	{ // �̷��� �Ȱɸ� �ٸ����� ���� isOnceKeyDown(VK_RETURN)�� ����Ǵ°� ����
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SOUNDMANAGER->play("����", 1.0f);
			SCENEMANAGER->changeScene("Ÿ��Ʋ��");
			_videoPlaying = false;
		}
	}

	SCENEMANAGER->update();
	EFFECTMANAGER->update();
}


void playGround::render()
{
	if (_videoPlaying) return;
	PatBlt(getMemDC(), 0, 0, CAMX + WINSIZEX, CAMY + WINSIZEY, WHITENESS);
	//================ ���� �ǵ��� ���� ==============================

	SCENEMANAGER->render();
	EFFECTMANAGER->render();

	//================= �Ʒ��� �ǵ��� ���� ==============================
	_backBuffer->render(getHDC(), 0, 0, CAMX, CAMY, WINSIZEX, WINSIZEY);
}