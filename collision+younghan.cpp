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

	if (_pl->getEnumState() == GRABSWING)
	{
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			RECT sour;
			if (_em->getVEnemy()[i]->getState() == E_HIT || _em->getVEnemy()[i]->getState() == E_DEAD) continue;
			if (IntersectRect(&sour, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
			{
				for (int j = 0; j < _pl->getAttack()->getVAttack().size(); ++j)
				{
					RECT temp;
					if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRect(), &_pl->getAttack()->getVAttack()[j].rc))
					{
						int effectSound = RND->getInt(4);
						switch (effectSound)
						{
						case 0:
							SOUNDMANAGER->play("Ÿ��1");
							break;
						case 1:
							SOUNDMANAGER->play("Ÿ��2");
							break;
						case 2:
							SOUNDMANAGER->play("Ÿ��3");
							break;
						case 3:
							SOUNDMANAGER->play("Ÿ��4");
							break;
						default:
							break;
						}
						if (_em->getVEnemy()[i]->getState() == E_GRAB)
						{
							_em->getVEnemy()[i]->getState() = E_FLYING;
							_em->getVEnemy()[i]->getDamage(20);
						}
						_score += 100;
						hitted = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			RECT sour;
			if (_em->getVEnemy()[i]->getState() == E_HIT || _em->getVEnemy()[i]->getState() == E_DEAD) continue;
			if (IntersectRect(&sour, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
			{
				for (int j = 0; j < _pl->getAttack()->getVAttack().size(); ++j)
				{
					RECT temp;
					if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRect(), &_pl->getAttack()->getVAttack()[j].rc))
					{
						int effectSound = RND->getInt(4);
						switch (effectSound)
						{
						case 0:
							SOUNDMANAGER->play("Ÿ��1");
							break;
						case 1:
							SOUNDMANAGER->play("Ÿ��2");
							break;
						case 2:
							SOUNDMANAGER->play("Ÿ��3");
							break;
						case 3:
							SOUNDMANAGER->play("Ÿ��4");
							break;
						default:
							break;
						}
						_em->getVEnemy()[i]->getState() = E_HIT;
						_em->getVEnemy()[i]->getDamage(20);
						_score += 100;
						hitted = true;
						break;
					}
				}
				for (int i = 0; i < _em->getVEnemy().size(); ++i)
				{
					if (_pl->getIsGrab()) break;
					RECT temp;
					if (IntersectRect(&temp, &_pl->getFlyRc(), &_em->getVEnemy()[i]->getRect()))
					{
						if (temp.right - temp.left > (_em->getVEnemy()[i]->getRect().right - _em->getVEnemy()[i]->getRect().left) / 3 && _pl->getFlyY() - _em->getVEnemy()[i]->getY() < 4
							&& _pl->getFlyY() - _em->getVEnemy()[i]->getY() > -4 && (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)))
						{
							if (_pl->getLeft()) _em->getVEnemy()[i]->getLeft() = false;								
							else _em->getVEnemy()[i]->getLeft() = true;
							_em->getVEnemy()[i]->setState(E_GRAB);
							_pl->getIsGrab() = true;
							break;
						}
					}
				}
			}

		}
	}
	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{
		if (_pl->getIsHit()) break;
		RECT temp;
		if (IntersectRect(&temp, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
		{
			if (IntersectRect(&temp, &_pl->getFlyRc(), &_em->getVEnemy()[i]->getAtkRc()))
			{
				_pl->getIsHit() = true;
				_em->getVEnemy()[i]->getAtkRc() = RectMake(0, 0, 0, 0);
				break;
			}
		}

	}
}

void collision::younghanRender()
{
}
