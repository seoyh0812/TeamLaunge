#pragma once
#include "gameNode.h"


class item :public gameNode
{
protected:
	RECT _rc;
	float _x; float _y;
	image* _image;

	bool _pickup; //����ֳ���?->�տ� ��� ���� �� �� ����.
	bool _moving; //�����̳���?->������ �� ó���� �� ����.
public:
	item();
	~item();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void fillColorEllipse(int R, int G, int B, RECT rc);
	RECT getRect() { return _rc; }

	//�Ʒ��� �� �� �Ŵ������� ����� �Լ���.
	//������ �߻��ϵ�����. ������ �������ָ�(true : ������, false : ����) x, y�� �����̵��� ��.
	virtual void attackMove(bool direction);
	//�������� ��� �ִ��� �Ǵ��� �Լ�. true:��� ����. false:��� ���� ����. x, y : ���ٴ� �� ��ġ ����.
	virtual void setHold(bool holding, float x, float y);
	
};

