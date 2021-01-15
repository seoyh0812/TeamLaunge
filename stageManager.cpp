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
		//if (!_VObject[i]->getIsBossOn()) // ���� ���� ���̶��. 
		//{
			createChair(3100 + (i * 360), 465);
		//}
	}

	//// ���� ���� �� ���� ��ġ����.  (�������� �ʿ��� - ������ �����ϰԵǸ� ��Ÿ���� �ȴ�.) ���� �����ϰ� �����. 
	/*for (int i = 0; i < 3; i++)
	{
		createChair(3135 + (i * 360), 490);
		for (int j = 0; j < 3; j++)
		{
			createChair(3300 + (j * 355), 760);
		}
	}*/


	return S_OK;
}

void stageManager::release()
{
	_VObject.clear(); // ������ü�� ���ֹ����� �Լ�.
}

void stageManager::update()
{
	for (int i = 0; i < _VObject.size(); ++i)
	{
		_VObject[i]->update();
	}


	for (int i = 0; i < _VObject.size(); ++i)
	{
		if (!_VObject[i]->getIsFire()) // _isFireȮ��
		{
			removeObject(i);
			break;
		}
	}
	

}

void stageManager::render()
{ // ������Ʈ ���͵��� ��Ʈ�������� �ѹ��� �׸�����
}

//----------------------------------------------------------------------------------------------------------
// 1-1.�浹�Լ����� �浹���� Ȯ�� > 2.Ȯ�εȴٸ� removeObject()�� �ͼ� ������������ �Ǻ� > ���������� �´ٸ� �����شٴ� ��ȹ.
// 2-1.�浹�Լ����� �浹���� Ȯ�� > 2.Ȯ�εȴٸ� removeObject()�� �ͼ� �������� �Ǻ� > ���ڰ� �´ٸ� && �÷��̾ �������̶�� �����ش�.
// 2-1.�浹�Լ����� �浹���� Ȯ�� > 2.Ȯ�εȴٸ� removeObject()�� �ͼ� �������� �Ǻ� > ���ڰ� �´ٸ� && �÷��̾ ��ȣ�ۿ����̶�� ���з� ����.

// �浹 �� �Ͼ �ϵ�.
void stageManager::removeObject(int arrNum) // arrNum���⿡ i�� ���� �ȴ�. 
{
	//�ܺο��� Ư�� �ָ� ��������ؼ� �װ͸� ����� �Լ�
	// id�� ã�� (�� Ŭ����(����, ��������)���� id�� �ٿ��ش�. (���� = 0, �������� = 1) �׸��� �� id�� ���� �������� ������������ Ȯ���ϰԵȴ�.)
	if (_VObject[arrNum]->getId() == 0) // 0 > �����̴�.
	{
		_VObject.erase(_VObject.begin() + arrNum);
	}
	else if (_VObject[arrNum]->getId() == 1) // 1 > ���������̴�. 
	{
		_VObject.erase(_VObject.begin() + arrNum);
	}



	/*
	if (_FINDIMG("��������"))
	{
		_VObject.erase(_VObject.begin() + arrNum);
	}
	if (_img == FINDIMG("����"))
	{
		if (�÷��̾ ���ݻ����϶�)
		{
			// ���ڰ� �������. 
			_VObject.erase(_VObject.begin() + arrNum);
		}

		if (�÷��̾ ���ڿ��� ��ȣ�ۿ�Ű�� ��������)
		{
			// ���ڰ� ���а� �ȴ�. (������ ����� ���������� �÷��̾��� ��Ʈ�� �ٰԵȴ�. (�÷��̾ �������� ��, ������ �� ������ ���⵵ �޶�����.)) 
		}
	}
	*/
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
