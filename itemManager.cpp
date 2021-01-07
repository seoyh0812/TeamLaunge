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
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{//����� 
		_vItem.clear();
		createBaseball(300, CAMY + 500);
	}

	for (int i = 0; i < _vItem.size(); ++i)
	{
		_vItem[i]->update();
	}

	for (int i = 0; i < _vItem.size(); i++)
	{//�������� ȭ�� ������ ������ ����������.
		if (_vItem[i]->getRect().right < CAMERAMANAGER->getCameraX() ||
			_vItem[i]->getRect().left > CAMERAMANAGER->getCameraX() + WINSIZEX)
		{
			_vItem.erase(_vItem.begin() + i);
			break;
		}
	}
}

void itemManager::render()
{ // �����۵��� ��Ʈ�������� �ѹ��� �׸�����
}

void itemManager::createBaseball(float x, float y)
{
	baseball* vbaseball;
	vbaseball = new baseball;
	vbaseball->init(x, y);
	_vItem.push_back(vbaseball);
}
