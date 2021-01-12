#include "stdafx.h"
#include "collision.h"


void collision::deokhoInit()
{
}

void collision::deokhoUpdate()
{
	RECT temp;
	for (int i = 0; i < _im->getVItem().size(); i++)
	{// ������ ��� ������. �Ա�
		if (IntersectRect(&temp, &_pl->getFlyRc(), &_im->getVItem()[i]->getRect()))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (_im->getVItem()[i]->isFood()) //���� ����.
				{
					SOUNDMANAGER->play("�Դ¼Ҹ�");
					_im->getVItem()[i]->setHold();
				}

				if (!_im->getVItem()[i]->isFood())
				{//���� �� �ƴ� : ���̳� ��ź���� ���� �����ų� �ϴ� �͵�
					if (!_im->getVItem()[i]->getPickup() && !_im->getVItem()[i]->getMoving())
					{//�ݱ�-> ������� �ʰ�, �����̵��� ���� ����.
						_im->getVItem()[i]->setHold(_pl->getFlyX(), _pl->getFlyY(), _pl->getFlyRc().bottom);
						return;
					}
					if (_im->getVItem()[i]->getPickup() && !_im->getVItem()[i]->getMoving())
					{//������. ����ְ�, �����̵��� ���� ����.
						if (_im->getVItem()[i]->getID() != 0)	SOUNDMANAGER->play("������");
						_im->throwing(!_pl->getLeft());
						_im->getVItem()[i]->attackMove(_pl->getLeft());
					}
				}
			}
		}
		if (_im->getVItem()[i]->getPickup() == true) _im->getVItem()[i]->setHold(_pl->getFlyX(), _pl->getFlyY(), _pl->getFlyRc().bottom);
		//if(����ִ� ����) ������ ��ġ ��� �ʱ�ȭ.
	}

	for (int i = 0; i < _im->getVItem().size(); ++i)
	{//������ ����.
		for (int j = 0; j < _em->getVEnemy().size(); ++j)
		{//�� ����
			if (_im->getVItem()[i]->getMoving())
			{//�������� �����̶�� ��ɹ��� ������?? -> ������ �����.
				if (IntersectRect(&temp, &_im->getVItem()[i]->getRect(), &_em->getVEnemy()[i]->getRect()))
				{//�浹�ߴ�?
					if (_im->getVItem()[i]->getID() == 1)
					{//�߱����̴�?
						SOUNDMANAGER->play("Ÿ��2");
						if (_im->getVItem()[i]->getDirection()) _im->getVItem()[i]->makeInflect(+1.5f);
						//���������� ��������?
						else _im->getVItem()[i]->makeInflect(1.5f);
					}
					if (_im->getVItem()[i]->getID() == 2)
					{
						
						_im->getVItem()[i]->makeBoom();
					}
				}
			}
		}
	}

}

void collision::deokhoRender()
{
}
