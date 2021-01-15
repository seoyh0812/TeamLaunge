#include "stdafx.h"
#include "collision.h"


void collision::younghanInit()
{
}

void collision::younghanUpdate()
{
	//�÷��̾� ���� ��Ʈ�� ���ʹ� ��Ʈ �浹�� HIT���·� �����Ű�� ü���� ����

	//�÷��̾��� ���°� GRABSWING�̶��
	if (_pl->getEnumState() == GRABSWING)
	{
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			RECT sour;
			//������ phase�� �����ϴ� boss��� phase 1, 2�����϶� ������ �Ұ����ϵ��� ����
			if (_em->getVEnemy()[i]->getPhase() == 1 || _em->getVEnemy()[i]->getPhase() == 2) continue;

			//���� �̹� E_HIT�����̰ų� E_DEAD���¶�� ������ �Ұ����ϵ��� ����
			if (_em->getVEnemy()[i]->getState() == E_HIT || _em->getVEnemy()[i]->getState() == E_DEAD) continue;

			//���� �÷��̾��� �׸��ڰ� �浹�ǰ�
			if (IntersectRect(&sour, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
			{
				for (int j = 0; j < _pl->getAttack()->getVAttack().size(); ++j)
				{
					RECT temp;
					//���� ��Ʈ�� �÷��̾��� ���ݷ�Ʈ�� �浹�Ǹ�
					if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRect(), &_pl->getAttack()->getVAttack()[j].rc))
					{
						//�ߺ� �������� �����ϱ����� ���ݷ�Ʈ�� �����ϰ�
						_pl->getAttack()->removeAttack(j);

						//????
						if (_em->getVEnemy()[i]->getState() == E_GRAB && _pl->getFlyCount() >= 20)
						{
							//���� ���¸� E_FLYING���� ����
							_em->getVEnemy()[i]->getState() = E_FLYING;
						}
						_score += 100; //������ 100��ŭ �����ش�
						break;
					}
				}
			}
		}
	}
	else//�÷��̾ GRABSWING���°� �ƴ϶��
	{
		for (int i = 0; i < _em->getVEnemy().size(); ++i)
		{
			RECT sour;
			//������ phase�� �����ϴ� boss��� phase 1, 2�����϶� ������ �Ұ����ϵ��� ����
			if (_em->getVEnemy()[i]->getPhase() == 1 || _em->getVEnemy()[i]->getPhase() == 2) continue;

			//���� �̹� E_HIT�����̰ų� E_DEAD���¶�� ������ �Ұ����ϵ��� ����
			if (_em->getVEnemy()[i]->getState() == E_HIT || _em->getVEnemy()[i]->getState() == E_DEAD) continue;

			//���� �÷��̾��� �׸��ڰ� �浹�ǰ�
			if (IntersectRect(&sour, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
			{
				for (int j = 0; j < _pl->getAttack()->getVAttack().size(); ++j)
				{
					RECT temp;
					//���� ��Ʈ�� �÷��̾��� ���ݷ�Ʈ�� �浹�Ǹ�
					if (IntersectRect(&temp, &_em->getVEnemy()[i]->getRect(), &_pl->getAttack()->getVAttack()[j].rc))
					{
						//���� ���带 ��½�Ű��
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
						_em->getVEnemy()[i]->setAlpha(); //enemy�� ���ĸ� 255�� ����
						_em->getVEnemy()[i]->setAtkNum(); //enemy1�̶�� �ǰݸ���� �������� ��½�Ű��
						_em->getVEnemy()[i]->getState() = E_HIT; //enemy�� E_HIT���·� ����
						_em->getVEnemy()[i]->getDamage(20); //enemy���� 20�� �������� ���Ѵ�
						_score += 100; //������ 100��ŭ �����ش�
						break;
					}
				}
				for (int i = 0; i < _em->getVEnemy().size(); ++i)
				{
					//????
					if (_pl->getIsGrab()) break;
					RECT temp;

					//�÷��̾��� ��Ʈ�� ���� ��Ʈ�� �浹�ϰ�
					if (IntersectRect(&temp, &_pl->getFlyRc(), &_em->getVEnemy()[i]->getRect()))
					{
						//�Ʒ��� ������ �����ȴٸ�
						if (temp.right - temp.left > (_em->getVEnemy()[i]->getRect().right - _em->getVEnemy()[i]->getRect().left) / 3 && _pl->getFlyY() - _em->getVEnemy()[i]->getY() < 4
							&& _pl->getFlyY() - _em->getVEnemy()[i]->getY() > -4 && (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_RIGHT)))
						{
							if (_pl->getLeft()) _em->getVEnemy()[i]->getLeft() = false; //�÷��̾ ������ �����ִٸ� ���� ��������	���Ը����		
							else _em->getVEnemy()[i]->getLeft() = true; //�÷��̾ �������� �����ִٸ� ���� ������ ���Ը����
							_em->getVEnemy()[i]->setState(E_GRAB); //���� E_GRAB���·� ����
							_pl->getIsGrab() = true; //??
							break;
						}
					}
				}
			}

		}
	}
	for (int i = 0; i < _em->getVEnemy().size(); ++i)
	{
		//�÷��̾ HIT, GRAB, DEAD���°� �ƴ϶��
		if (_pl->getEnumState() == HIT || _pl->getEnumState() == GRAB || _pl->getEnumState() == DEAD) break;
		RECT temp;
		//���� �׸��ڿ� �÷��̾ �浹�ǰ�
		if (IntersectRect(&temp, &_em->getVEnemy()[i]->getShadow(), &_pl->getShadow()))
		{
			//�÷��̾�� ���� ���ݷ�Ʈ�� �浹�Ǹ�
			if (IntersectRect(&temp, &_pl->getFlyRc(), &_em->getVEnemy()[i]->getAtkRc()))
			{
				_pl->setState(HIT); //�÷��̾��� ���¸� HIT�� ����
				_em->getVEnemy()[i]->getAtkRc() = RectMake(0, 0, 0, 0); //���� ���ݷ�Ʈ�� ��ġ�� ����
				break;
			}
		}
	}
}

void collision::younghanRender()
{
}
