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
	// �߰��ϴ� �Լ�. ���߿� ��ġ�ҋ� ���� ������ ������ ��

	// �������� 1 �������� ��ġ����. (�������� ���ʿ�)
	createTrashCan(600, CAMY + 500);
	createTrashCan(1450, CAMY + 450);
	createTrashCan(1300, CAMY + 650);

	// ������������ �������� ��ġ����.  (�������� ���ʿ�)
	createTrashCan(4400, 450);
	createTrashCan(4500, 700);

	// ���� ���� �� ���� ��ġ����. (�������� ���ʿ�)
	for (int i = 0; i < 3; i++)
	{
		createChair(3200 + (i * 350), 420);
	}

	//// ���� ���� �� ���� ��ġ����.  (�������� �ʿ��� - ������ �����ϰԵǸ� ��Ÿ���� �ȴ�.) ���� �����ϰ�, ���� ���°� �����ϰ� �����. 
	//for (int i = 0; i < 9; i++)
	//{
	//  for (int j = 0; j < 3; j++)
	//	{
	//		createChair(3200 + (i * 370), 420 + ( j * 120));
	//  }
	//}


	return S_OK;
}

void stageManager::release()
{
	_VObject.clear();
}

void stageManager::update()
{
	for (int i = 0; i < _VObject.size(); ++i)
	{
		_VObject[i]->update();
	}
}

void stageManager::render()
{ // ������Ʈ ���͵��� ��Ʈ�������� �ѹ��� �׸�����
}

void stageManager::createChair(float x, float y)
{
	chair* vchair;
	vchair = new chair;
	vchair->init(x, y); // ���ڸ� ���� �̴��϶�. 
	_VObject.push_back(vchair); // ���;ȿ� vchair(���ڸ� init�� ��ü�ϳ�)�� ����־��.
}

void stageManager::createTrashCan(float x, float y)
{
	trashCan* vTrashCan;
	vTrashCan = new trashCan;
	vTrashCan->init(x, y);
	_VObject.push_back(vTrashCan);
}

