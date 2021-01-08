#pragma once
#include "gameNode.h"
#include "baseball.h"
#include "bat.h"
#include "bomb.h"
#include <vector>

class itemManager :	public gameNode
{
private:
	vector<item*> _vItem;
	vector<item*>::iterator _viItem;
	// (�߿���) ���Ϳ��� ���ʹ̷ν�(�θ�Ŭ����) �ִ°ž�
	// ���� subclass���� ������ �Լ��� ����� �̿��ϰ� �ʹٸ�
	// [ex) (�ٸ�Ŭ��������) getVItem()[i]->�����Լ�();]
	// ����� �� ���ٰ� ������ ��ž�. (���ͳ��� itemŬ������� �ν��ϰ� �־�)

	// �׷��� item.h���� " ������ �Լ�() = 0; " �䷱������ ������ �Լ��� �����Ҽ� �־�.
	// �׷��� item�� �� �Լ��� ������ ������ �ȳ����� item�� �Լ��� �ƴ� ���Ŭ������ �� �����ϰ� ��
	bool itemAttack;
	bool _direction;
public:
	itemManager();
	~itemManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	void createBaseball(float x, float y);
	void createBomb(float x, float y);
	void throwing();
	void throwing(bool direction);
	vector<item*> getVItem() { return _vItem; }
	vector<item*>::iterator getViItem() { return _viItem; }
};

