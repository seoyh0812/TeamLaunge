#include "stdafx.h"
#include "collision.h"


void collision::yoonghoInit()
{
}

void collision::yoonghoUpdate()
{
	// ############ �������� ������ ������Ʈ��� ���ι����ϴ� ��� ######################
	RECT temp1;
	RECT temp2 = RectMakeCenter(_pl->getGroundX(), _pl->getGroundRc().bottom -10,  50, 20);// 50�� ���߿� �÷��̾� �ʺ�����ϸ� �����Ұ�
	for (int i = 0; i<_sm->getVObject().size(); ++i)
	{
		if (_sm->getVObject()[i]->getId() == 1) continue; // ���ڶ� ������ ��Ʈ��(��ֹ�) ����
		RECT temp3 = _sm->getVObject()[i]->getRect();
		if (IntersectRect(&temp1, &temp2, &temp3))
		{
			if (temp1.right - temp1.left > temp1.bottom - temp1.top)
			{//���Ʒ��� �ε�
				if (temp2.top < temp1.top)
				{ // �Ʒ��� �ε�
					_pl->getFlyY() -= temp1.bottom - temp1.top;
					_pl->getGroundY() -= temp1.bottom - temp1.top;
				}
				else
				{ // ���κε�
					_pl->getFlyY() += temp1.bottom - temp1.top;
					_pl->getGroundY() += temp1.bottom - temp1.top;
				}
			}
			else // �¿�� �ε�
			{
				if (temp2.left < temp1.left)
				{ // ��������
					_pl->getFlyX() -= temp1.right - temp1.left;
					_pl->getGroundX() -= temp1.right - temp1.left;
				}
				else
				{ // ���κε�
					_pl->getFlyX() += temp1.right - temp1.left;
					_pl->getGroundX() += temp1.right - temp1.left;
				}
			}
		}
	}
}

void collision::yoonghoRender()
{
}
