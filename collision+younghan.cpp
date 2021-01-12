#include "stdafx.h"
#include "collision.h"


void collision::younghanInit()
{
}

void collision::younghanUpdate()
{
	//�÷��̾� ���� ��Ʈ�� ���ʹ� ��Ʈ �浹�� HIT���·� �����Ű�� ü���� ����
	bool hitted;
	hitted = false;

	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{
		if (_em->getVEnemy()[i]->getState() == E_HIT || _em->getVEnemy()[i]->getState() == E_DEAD) continue;
		for (int j = 0; j < _pl->getAttack()->getVAttack().size(); ++j)
		{
			RECT temp;
			if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRect(), &_pl->getAttack()->getVAttack()[j].rc))
			{
				_em->getVEnemy()[i]->getState() = E_HIT;
				hitted = true;
			}
		}
	}

	if (hitted) _pl->getAttack()->getVAttack().clear();
}

void collision::younghanRender()
{
}
