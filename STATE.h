#pragma once
class player;

class STATE 
{
protected:
	player* _pl;
	// ������ ���µ鿡�� �÷��̾ ��ũ�� �޾ƿ� �� �ְ� ��������ϴ�
public:
	~STATE();
	virtual void EnterState() = 0;
	virtual void updateState() = 0;
	virtual void ExitState() = 0;
	// ���� �����ռ��� ����ؼ� ��ӹ޴� Ŭ�������� �ش� �Լ��� �� �� �ְ� �߽��ϴ�

	void LinkMemberAdress(player* player)	{_pl = player;}
};
