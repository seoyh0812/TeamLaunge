#include "stdafx.h"
#include "mainScene.h"


void mainScene::zOrderRender()
{ // ###################### z���� ���� ������� ##################
	int temp;
	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _em->getVEnemy()[i]->getRect().bottom; // �̰� ����
		bottomY.push_back(temp);
	}
	for (int i = 0; i < _sm->getVObject().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _sm->getVObject()[i]->getRect().bottom; // �̰� ������Ʈ��
		bottomY.push_back(temp);
	}
	for (int i = 0; i < _im->getVItem().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _im->getVItem()[i]->getRect().bottom; // �̰� �����۵�
		bottomY.push_back(temp);
	}
	temp = _pl->getGroundRc().bottom; // �̰� �÷��̾�
	bottomY.push_back(temp);
	// y���� �ϳ��ϳ� �־���
	
	for (int i = 0; i < bottomY.size() - 1; ++i)
	{
		for (int j = i + 1; j > 0 && bottomY[j] < bottomY[j - 1]; --j)
		{
			swap(bottomY[j], bottomY[j - 1]);
		}
	}	// ���� �˰����� ���� �����̾�
	// �ݺ����� �� �м��Ѵٸ� �� �� �ְ�����, ���������� �ݺ����� ���µ�
	// ���ǰ��� ���ǰͺ��� �۴ٸ� swap(��ġ�ٲ�)�� �ݺ��ϴ� �ݺ����̶� ���� ��

	for (int i = 0; i < bottomY.size(); ++i)
	{ // ���������� ���Ϳ� ��� ������� �׸���� ��
		if (_pl->getGroundRc().bottom == bottomY[i])
		{ // ���� ã�� ���Ұ��� ��������?
			_pl->playerRender(); // �׷��ٸ� ����
		}
		for (int j = 0; j < _em->getVEnemy().size(); ++j)
		{
			if (_em->getVEnemy()[j]->getRect().bottom == bottomY[i])
			{
				_em->getVEnemy()[j]->render();
			}
		}
		for (int j = 0; j < _im->getVItem().size(); ++j)
		{
			if (_im->getVItem()[j]->getRect().bottom == bottomY[i])
			{
				_im->getVItem()[j]->render();
			}
		}
		for (int j = 0; j < _sm->getVObject().size(); ++j)
		{
			if (_sm->getVObject()[j]->getRect().bottom == bottomY[i])
			{
				_sm->getVObject()[j]->render();
			}
		}
	}
	bottomY.clear();

	//�ʹ� ��ȿ�������� ������..
}



void mainScene::uiRender()
{
	FINDIMG("�÷��̾�ui")->render(getMemDC(), CAMX + 170, CAMY);
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 466, CAMY + 30, _timeLimit / 10, 0);
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 513, CAMY + 30, _timeLimit % 10, 0);
	FINDIMG("�������")->frameRender(getMemDC(), CAMX + 359, CAMY + 53, _life, 0);
}