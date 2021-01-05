#include "stdafx.h"
#include "stageManager.h"

stageManager::stageManager()
{
}

stageManager::~stageManager()
{
}

HRESULT stageManager::init()
{
	// 추가하는 함수. 나중에 배치할떄 쓰고 지금은 지워도 됨
	createChair(400, CAMY + 400);

	return S_OK;
}

void stageManager::release()
{
	_vObject.clear();
}

void stageManager::update()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		_vObject[i]->update();
	}
}

void stageManager::render()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		_vObject[i]->render();
	}
}

void stageManager::createChair(float x, float y)
{
	chair* vchair;
	vchair = new chair;
	vchair->init(x, y);
	_vObject.push_back(vchair);
}
