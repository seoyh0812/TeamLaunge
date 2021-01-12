#include "stdafx.h"
#include "collision.h"


void collision::hyunjungInit()
{
}

void collision::hyunjungUpdate()
{

	for (int i = 0; i < _sm->getVObject().size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_pl->getAttack()->getAttackRect(), &_sm->getVObject()[i]->getRect()))
		{
			_sm->removeObject(i);
		}
	}

}

void collision::hyunjungRender()
{
}
