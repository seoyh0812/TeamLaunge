#pragma once
#include "gameNode.h"
#include "trashCan.h"
#include "chair.h" // ���Ŭ�����鸸 �־��൵ ��.

class stageManager : public gameNode
{
private:
	vector<object*> _vObject;
	vector<object*>::iterator _viObject;
	// (�߿���) ���Ϳ��� ���ʹ̷ν�(�θ�Ŭ����) �ִ°ž�
	// ���� subclass���� ������ �Լ��� ����� �̿��ϰ� �ʹٸ�
	// [ex) (�ٸ�Ŭ��������) getVObject()[i]->�����Լ�();]
	// ����� �� ���ٰ� ������ ��ž�. (���ͳ��� objectŬ������� �ν��ϰ� �־�)

	// �׷��� object.h���� " ������ �Լ�() = 0; " �䷱������ ������ �Լ��� �����Ҽ� �־�.
	// �׷��� object�� �� �Լ��� ������ ������ �ȳ����� object�� �Լ��� �ƴ� ���Ŭ������ �� �����ϰ� ��

public:
	stageManager();
	~stageManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void createChair(float x, float y);

	vector<object*> getVObject() { return _vObject; }
	vector<object*>::iterator getViObject() { return _viObject; }
};

