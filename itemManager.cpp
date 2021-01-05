#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager()
{
}

itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	createBaseball(300, CAMY + 500);
	return S_OK;
}

void itemManager::release()
{
	_vItem.clear();
}

void itemManager::update()
{
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->update();
	}
}

void itemManager::render()
{
	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->render();
	}
}

void itemManager::createBaseball(float x, float y)
{
	baseball* vbaseball;
	vbaseball = new baseball;
	vbaseball->init(x, y);
	_vItem.push_back(vbaseball);
}
