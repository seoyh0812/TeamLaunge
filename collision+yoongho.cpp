#include "stdafx.h"
#include "collision.h"


void collision::yoonghoInit()
{
}

void collision::yoonghoUpdate()
{
	// ############ �������� ������ ������Ʈ��� ���ι����ϴ� ��� ######################
	//RECT temp1;	
	//RECT temp2 = _pl->getShadow();// 50�� ���߿� �÷��̾� �ʺ�����ϸ� �����Ұ�
	//for (int i = 0; i < _sm->getVObject().size(); ++i)
	//{
	//	if (_sm->getVObject()[i]->getId() != 0) continue; // ���ڶ� ������ ��Ʈ��(��ֹ�) ����
	//	RECT temp3 = _sm->getVObject()[i]->getRect();
	//	int x = (temp3.left + temp3.right) / 2;
	//	int y = (temp3.bottom+ temp3.top)/2;
	//	temp3 = RectMakeCenter(x + 30, y + 90, 130, 100);
	//	if (IntersectRect(&temp1, &temp2, &temp3))
	//	{
	//		if (temp1.right - temp1.left > temp1.bottom - temp1.top)
	//		{//���Ʒ��� �ε�
	//			if (temp2.top < temp1.top)
	//			{ // �Ʒ��� �ε�
	//				_pl->getFlyY() -= temp1.bottom - temp1.top;
	//				_pl->getGroundY() -= temp1.bottom - temp1.top;
	//			}
	//			else
	//			{ // ���κε�
	//				_pl->getFlyY() += temp1.bottom - temp1.top;
	//				_pl->getGroundY() += temp1.bottom - temp1.top;
	//			}
	//		}
	//		else // �¿�� �ε�
	//		{
	//			if (temp2.left < temp1.left)
	//			{ // ��������
	//				_pl->getFlyX() -= temp1.right - temp1.left;
	//				_pl->getGroundX() -= temp1.right - temp1.left;
	//			}
	//			else
	//			{ // ���κε�
	//				_pl->getFlyX() += temp1.right - temp1.left;
	//				_pl->getGroundX() += temp1.right - temp1.left;
	//			}
	//		}
	//	}
	//}
}

void collision::yoonghoRender()
{
}
