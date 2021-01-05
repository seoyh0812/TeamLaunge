#pragma once
class player;

class STATE 
{
protected:
	player* _pl;
	// ���Ŭ�����鵵 player�� ��Ī?�ϴ� _pl�� ���������� ���°�
	// �ٵ� �̰͸� ������ ���������?
	// player.cpp���� �����Ҵ�ɶ����� ��ũ�Լ�(�ؿ��ִ�)�� ������ �����ִ� ��
	// �츮�� �����Ҷ� �����ϴ��Ͱ� ���� ������
public:
	~STATE();
	virtual void EnterState()=0;
	virtual void updateState() = 0;
	virtual void ExitState() = 0;
	// ��ӵ� ����Ŭ������ �� �Լ��� �̿��� �� �ֵ��� �Լ����� ���������� ����?���������� �� �Լ��� ������ ��������� �ʴ´�.
	// = 0�� ����� �׷� �����̷�. Ȥ�ö� �̰ɷδ� ������ϵ��� �ϴ� ����
	// �װ� interface�ϱ�..

	void LinkMemberAdress(player* player)	{_pl = player;}
};
