#pragma once
#include "gameNode.h"


class item :public gameNode
{
protected:
	RECT _rc;//���߷�Ʈ
	float _x; float _y;
	image* _image;

	RECT _rcg;//����Ʈ
	float _xg, _yg;
	float _gravity;

	RECT _shadow;//�׸���.
	int _distance;//���߷�Ʈ, ����Ʈ ��ġ����.
	float _time;//�̹���, ��Ȳ ��ȯ�� ����.
	
	float _angle; //�̵��� �� �̿��ؼ� ���ϰ�.

	bool _pickup; //����ֳ���?->�տ� ��� ���� �� �� ����.
	bool _moving; //�����̳���?->������ �� ó���� �� ����.
	bool _delete; //�Ŵ������� ������ ��ȣ�� �� ����.

public:
	item();
	~item();

	virtual HRESULT init(float x, float y);
	//������ ������ �� �̰ɷ� ���Կ�. x, y ���߷�Ʈ ����. bottom = ����Ʈ.bottom
	virtual HRESULT init(float x, float y, float bottom);
	virtual void release();
	virtual void update();
	virtual void render();

	void shadowRender(RECT rc);
	void fillColorEllipse(int R, int G, int B, RECT rc);

	RECT getRect() { return _rc; }

	inline bool getDelete() { return _delete; }
	inline bool getPickup() { return _pickup; }
	inline bool getMoving() { return _moving; }

	//�Ʒ��� �� �� �Ŵ������� ����� �Լ���.
	//������ �߻��ϵ�����. ������ �������ָ�(true : ������, false : ����) x, y�� �����̵��� ��.
	virtual void attackMove(bool direction);
	//�������� ��� �ִ��� �Ǵ��� �Լ�. true:��� ����. false:��� ���� ����. x, y : ���ٴ� �� ��ġ ����.
	virtual void setHold(float x, float y);

	
};

