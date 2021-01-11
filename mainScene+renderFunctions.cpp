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

	if (bottomY.size() > 1 ) QuickSort(0, bottomY.size() - 1); // �̰� ������

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{

		for (int i = 0; i < bottomY.size(); ++i)
		{
			sprintf_s(_str, "%d", bottomY[i]);
			TextOut(getMemDC(), CAMX + 80 * i, CAMY + 100, _str, strlen(_str));
		}

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
	FINDIMG("�׳��ؽ�Ʈ")->frameRender(getMemDC(), CAMX + 670, CAMY, _timeLimit % 2, 0);
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 466, CAMY + 30, _timeLimit / 10, 0);
	FINDIMG("�ʷϼ���")->frameRender(getMemDC(), CAMX + 513, CAMY + 30, _timeLimit % 10, 0);
	FINDIMG("�������")->frameRender(getMemDC(), CAMX + 359, CAMY + 53, _life, 0);

	// _score = _cl->getScore();
	_score = 1500;
	FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 359, CAMY + 29, _score%10, 0);
	if (_score > 9)		FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 335, CAMY + 29, _score / 10 % 10, 0);
	if (_score > 99)	FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 311, CAMY + 29, _score / 100 % 10, 0);
	if (_score > 999)	FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 287, CAMY + 29, _score / 1000 % 10, 0);
	if (_score > 9999)	FINDIMG("�Ͼ����")->frameRender(getMemDC(), CAMX + 263, CAMY + 29, _score / 10000 % 10, 0);

	// _playerHpRatio = _pl->getCurrentHp()/100.f;
	// _bossHpRatio = _em->;

	if (_playerHpRatio > 0) _playerHpRatio -= 0.01f;
	else _playerHpRatio = 1.f; // Ȯ�ο�

	if (_playerHpRatio < 0.3f)
	{
		FINDIMG("�����϶�")->frameRender(getMemDC(), CAMX + 173, CAMY + 31, _redCount/15, 0);
	}
	FINDIMG("�÷��̾�ü�¹�")->render(getMemDC(), CAMX + 245, CAMY + 81, 132 - 132 * _playerHpRatio, 0, 132 * _playerHpRatio, 18);
	
	if (_bossHpRatio > 0) _bossHpRatio -= 0.01f;
	else _bossHpRatio = 1.f; // Ȯ�ο� 576 96 6~570
	FINDIMG("�����ؽ�Ʈ")->render(getMemDC(), CAMX + 428, CAMY + 176);
	if (_bossHpRatio > 0.5f) FINDIMG("����ü�¹�")->render(getMemDC(), CAMX + 224, CAMY + 200, 0, 24, 576, 24);
	else  FINDIMG("����ü�¹�")->render(getMemDC(), CAMX + 224, CAMY + 200, 0, 72, 576, 24);
	if (_bossHpRatio > 0.5f) FINDIMG("����ü�¹�")->render(getMemDC(), CAMX + 230, CAMY + 200, 576 - 570 * (_bossHpRatio -0.5f) * 2, 0, 570 * (_bossHpRatio - 0.5f) * 2, 24);
	else  FINDIMG("����ü�¹�")->render(getMemDC(), CAMX + 230, CAMY + 200, 576 - 570 * (_bossHpRatio) * 2, 48, 570 * (_bossHpRatio) * 2, 24);
	
}

int mainScene::paritition(int left, int right)
{
	int pivot = bottomY[left];//�ǹ��� ��ġ�� ���� ���ʿ��� ����
	int low = left + 1;
	int high = right;

	while (low <= high) // �����Ǳ� ������ �ݺ��Ѵ� 
	{
		while (low <= right && pivot >= bottomY[low]) // �ǹ����� ū ���� ã�� ���� 
		{
			low++; // low�� ���������� �̵� 
		}
		while (high >= (left + 1) && pivot <= bottomY[high])// �ǹ����� ���� ���� ã�� ����
		{
			high--; // high�� �������� �̵�
		}
		if (low <= high) // �������� ���� �����̸� ���� ���� ���� 
		{
			int temp = bottomY[low];
			bottomY[low] = bottomY[high];
			bottomY[high] = temp;
		}


	}
	// �ǹ��� high�� ����Ű�� ����� ��ȯ 
	int temp = bottomY[left];
	bottomY[left] = bottomY[high];
	bottomY[high] = temp;

	// �Ű��� �ǹ��� ��ġ������ ��ȯ 
	return high;
}

void mainScene::QuickSort(int left, int right)
{
	if (left < right)
	{
		int q = paritition(left, right);  // �ѷ� �����
		QuickSort(left, q - 1); // ���� ������ �����Ѵ�.
		QuickSort(q + 1, right); // ������ ������ �����Ѵ�.
	}
}