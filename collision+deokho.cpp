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
		if (IntersectRect(&temp, &_pl->getShadow(), &_im->getVItem()[i]->getShadow()))
		{
			if (KEYMANAGER->isOnceKeyDown('C'))
			{
				if (_im->getVItem()[i]->isFood()) //���� ����.
				{
					SOUNDMANAGER->play("�Դ¼Ҹ�");
					EFFECTMANAGER->play("��������", _im->getVItem()[i]->getRect().left, _im->getVItem()[i]->getRect().top - 150);
					_im->getVItem()[i]->setHold();
					_pl->getPlHP() += 30.0f;
					if (_pl->getPlHP() > 100) _pl->getPlHP() = 100.0f;
				}

				if (!_im->getVItem()[i]->isFood())
				{//���� �� �ƴ� : ���̳� ��ź���� ���� �����ų� �ϴ� �͵�
					if (!_im->getVItem()[i]->getPickup() && !_im->getVItem()[i]->getMoving())
					{//�ݱ�-> ������� �ʰ�, �����̵��� ���� ����.
						_im->getVItem()[i]->setHold(_pl->getFlyX(), _pl->getFlyY() - 50, _pl->getFlyRc().bottom);
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
		if (_im->getVItem()[i]->getPickup() == true) _im->getVItem()[i]->setHold(_pl->getFlyX(), _pl->getFlyY() - 50, _pl->getFlyRc().bottom);
		//if(����ִ� ����) ������ ��ġ ��� �ʱ�ȭ.
	}

	for (int i = 0; i < _im->getVItem().size(); ++i)
	{//������ ����.
		for (int j = 0; j < _em->getVEnemy().size(); ++j)
		{//�� ����
			if (_im->getVItem()[i]->getMoving())
			{//�������� �����̶�� ��ɹ��� ������?? -> ������ �����.
				if (IntersectRect(&temp, &_im->getVItem()[i]->getShadow(), &_em->getVEnemy()[j]->getShadow()))
				{//�浹�ߴ�?
					if (_im->getVItem()[i]->getID() == 1)
					{//�߱����̴�?
						if(_em->getVEnemy()[j]->getState()!=E_HIT) SOUNDMANAGER->play("Ÿ��2");
						_em->getVEnemy()[j]->setState(E_HIT);
						if (_im->getVItem()[i]->getDirection()) _im->getVItem()[i]->makeInflect(-1.5f);
						//���������� ��������?
						else _im->getVItem()[i]->makeInflect(-1.5f);
					}
					if (_im->getVItem()[i]->getID() == 2)
					{//��ź�̴�?
						_em->getVEnemy()[j]->setState(E_DEAD);
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
