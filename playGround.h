#pragma once
#include "mainScene.h"
#include "endingScene.h"
#include "titleScene.h"
#include "videoScene.h"

class playGround : public gameNode
{
private:
	bool _videoPlaying;

public:
	playGround();
	~playGround();

	virtual HRESULT init();	//�ʱ�ȭ ���� �Լ�
	virtual void release();	//�޸� ���� �Լ�
	virtual void update();	//���� ����
	virtual void render();	//�׸��� ����

	void imageInit();
};

