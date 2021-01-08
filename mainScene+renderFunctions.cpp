#include "stdafx.h"
#include "mainScene.h"

void mainScene::zOrderRender()
{ // ###################### z���� ���� ������� ##################
	RECT temp;
	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _em->getVEnemy()[i]->getRect(); // �̰� ����
		if (temp.bottom > CAMY && temp.top <CAMY + WINSIZEY && temp.right >CAMX && temp.left < CAMX + WINSIZEX) bottomY.push_back(temp.bottom);
	}
	for (int i = 0; i < _sm->getVObject().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _sm->getVObject()[i]->getRect(); // �̰� ������Ʈ��
		if (temp.bottom > CAMY && temp.top <CAMY + WINSIZEY && temp.right >CAMX && temp.left < CAMX + WINSIZEX) bottomY.push_back(temp.bottom);
	}
	for (int i = 0; i < _im->getVItem().size(); ++i)
	{ // ���Ϳ� ��ü���� ��Ʈ.���Ұ��� �߰�(Ǫ�ù�)����
		temp = _im->getVItem()[i]->getRect(); // �̰� �����۵�
		if (temp.bottom > CAMY && temp.top <CAMY + WINSIZEY && temp.right >CAMX && temp.left < CAMX + WINSIZEX) bottomY.push_back(temp.bottom);		
	}
	temp = _pl->getGroundRc(); // �̰� �÷��̾�
	bottomY.push_back(temp.bottom);
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
	{
		sprintf_s(_str, "%d", bottomY[i]);
		TextOut(getMemDC(), CAMX+80 * i, CAMY+100, _str, strlen(_str));
	}

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
}


void mainScene::uiRender()
{
	FINDIMG("�÷��̾�ui")->render(getMemDC(), CAMX + 170, CAMY);
	//+174 +31
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 466, CAMY + 30, _timeLimit / 10, 0);
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 513, CAMY + 30, _timeLimit % 10, 0);
	FINDIMG("�������")->frameRender(getMemDC(), CAMX + 359, CAMY + 53, _life, 0);
	// _score = _cl->getScore();
	FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 359, CAMY + 29, _score%10, 0);
	if(_score>9) FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 335, CAMY + 29, _score / 10 % 10, 0);
	if (_score > 99) FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 311, CAMY + 29, _score / 100 % 10, 0);
	if (_score > 999) FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 287, CAMY + 29, _score / 1000 % 10, 0);
	if (_score > 9999) FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 263, CAMY + 29, _score / 10000 % 10, 0);
	
}