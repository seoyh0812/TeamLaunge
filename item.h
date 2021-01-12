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
	int _tall;
	float _time;//�̹���, ��Ȳ ��ȯ�� ����.

	int _ID; //������ ���� ���ؼ�.
	bool _direction;
	float _angle; //�̵��� �� �̿��ؼ� ���ϰ�.

	bool _pickup; //����ֳ���?->�տ� ��� ���� �� �� ����.
	bool _moving; //�����̳���?->������ �� ó���� �� ����.
	bool _delete; //�Ŵ������� ������ ��ȣ�� �� ����.
	bool _food;   //���� ���� ���� ���� Ȯ���սô�.

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
	RECT getShadow() { return _shadow; }

	inline int getID() { return _ID; }
	inline bool getDelete() { return _delete; }
	inline bool getPickup() { return _pickup; }
	inline bool getMoving() { return _moving; }
	inline bool isFood() { return _food; }
	inline bool getDirection() { return _direction; }


	//�Ʒ��� �� �� �Ŵ������� ����� �Լ���.
	//������ �߻��ϵ�����. ������ �������ָ�(true : ������, false : ����) x, y�� �����̵��� ��.
	virtual void attackMove(bool direction);
	//�������� ��� �ִ��� �Ǵ��� �Լ�. true:��� ����. false:��� ���� ����. x, y : ���ٴ� �� ��ġ ����.
	virtual void setHold();
	virtual void setHold(float x, float y);
	virtual void setHold(float x, float y, float bottom);

	//���̶� ���ݽÿ� �̿��� ��.
	inline void makeBoom() { _delete = true; }//��� ��ź
	inline void makeInflect(float angle) { _angle += angle; }//��� �߱���


};

