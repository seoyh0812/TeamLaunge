#include "stdafx.h"
#include "attack.h"

HRESULT attack::init(int attackMax)
{
	_attackMax = attackMax;
	_count = 10; // �ʱ⿡ ī��Ʈ �ο�
	return S_OK;
}

void attack::release()
{
}

void attack::update(int count)
{
	

	for (_viAttack = _vAttack.begin(); _viAttack != _vAttack.end();)
	{
		_count--; // ī��Ʈ�� �����ϸ� ���� ��Ʈ�� �����ϰ� ���� �ʱ�ȭ�ǰ� �߽��ϴ�
		if (_count <= 0)
		{
			_viAttack = _vAttack.erase(_viAttack);
            _count = 10;
		}
		else ++_viAttack;
	}



}

void attack::render()
{
	if(KEYMANAGER->isToggleKey(VK_TAB))
	{ 
		for (_viAttack = _vAttack.begin(); _viAttack != _vAttack.end(); ++_viAttack)
		{
			Rectangle(getMemDC(), _viAttack->rc);
		} 
	}
	
}

void attack::Attack(float x, float y)
{
	if (_attackMax < _vAttack.size()) return;
	tagAttack attack;
	ZeroMemory(&attack, sizeof tagAttack);
	attack.x = attack.attackX = x;
	attack.y = attack.attackY = y;

	attack.rc = RectMake(attack.x, attack.y, 150, 100); 
	_attackRect = RectMake(attack.x, attack.y, 150, 100); // ����_�ݸ������� �߰��Ѱ�1

	_vAttack.push_back(attack);
}

void attack::removeAttack(int arrNum)
{
	_vAttack.erase(_vAttack.begin() + arrNum);
}
