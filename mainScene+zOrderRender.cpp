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

	sprintf_s(_str, "������:");
	TextOut(getMemDC(), CAMX+340, CAMY, _str, strlen(_str));
	for (int i = 0; i < bottomY.size(); ++i)
	{
		sprintf_s(_str, "%d", bottomY[i]);
		TextOut(getMemDC(), CAMX + 400 + i * 40, CAMY, _str, strlen(_str));
	} // �ؽ�Ʈ�� ���ظ� �������� ��������� �־�þ�. ���߿� ���ٰ�


	for (int i = 0; i < bottomY.size() - 1; ++i)
	{
		for (int j = i + 1; j > 0 && bottomY[j] < bottomY[j - 1]; --j)
		{
			swap(bottomY[j], bottomY[j - 1]);
		}
	}	// ���� �˰����� ���� �����̾�
	// �ݺ����� �� �м��Ѵٸ� �� �� �ְ�����, ���������� �ݺ����� ���µ�
	// ���ǰ��� ���ǰͺ��� �۴ٸ� swap(��ġ�ٲ�)�� �ݺ��ϴ� �ݺ����̶� ���� ��

	sprintf_s(_str, "������:");
	TextOut(getMemDC(), CAMX+340, CAMY+20, _str, strlen(_str));
	for (int i = 0; i < bottomY.size(); ++i)
	{
		sprintf_s(_str, "%d", bottomY[i]);
		TextOut(getMemDC(), CAMX + 400 + i * 40, CAMY+20, _str, strlen(_str));
	} // �ؽ�Ʈ�� ���ظ� �������� ��������� �־�þ�. ���߿� ���ٰ�

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


