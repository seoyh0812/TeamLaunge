#pragma once
#include "item.h"
class pizza :public item
{
private:
	/*
	RECT _rc;//���߷�Ʈ
	float _x; float _y;
	image* _image;

	RECT _rcg;//����Ʈ
	float _xg, _yg;
	float _gravity;

	RECT _shadow;//�׸���.
	int _distance;//���߷�Ʈ, ����Ʈ ��ġ����.


	bool _pickup; //����ֳ���?->�տ� ��� ���� �� �� ����.
	bool _moving; //�����̳���?->������ �� ó���� �� ����.
	bool _delete; //�Ŵ������� ������ ��ȣ�� �� ����.
	*/
public:

	virtual HRESULT init(float x, float y);
	//virtual HRESULT init(float x, float y, float bottom);
	virtual void release();
	virtual void update();
	virtual void render();

	void drop();



	//�Ʒ��� �� �� �Ŵ������� ����� �Լ���.
	//������ �߻��ϵ�����. ������ �������ָ�(true : ������, false : ����) x, y�� �����̵��� ��.
	//�������� ��� �ִ��� �Ǵ��� �Լ�. true:��� ����. false:��� ���� ����. x, y : ���ٴ� �� ��ġ ����.
};

