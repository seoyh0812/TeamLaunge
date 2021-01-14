#include "stdafx.h"
#include "collision.h"


void collision::yoonghoInit()
{
}

void collision::yoonghoUpdate()
{ // �ƹ��� ������ �ʾ����� Ǯ��
	bool check = false;
	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{
		if (_pl->getEnumState() != GRAB) break;
		if (_em->getVEnemy()[i]->getState() == E_GRAB)
		{
			check = true;
			break;
		}
	}
	if (!check && _pl->getEnumState() == GRAB) _pl->setState(IDLE);
	
	// ��ų� ��⽺���� �ƴϸ� Ǯ��
	if (_pl->getEnumState() != GRAB && _pl->getEnumState() != GRABSWING)
	{
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			if (_em->getVEnemy()[i]->getState() == E_GRAB)
			{
				_em->getVEnemy()[i]->setState(E_WALK);
			}
		}
	}
}

void collision::yoonghoRender()
{
}
