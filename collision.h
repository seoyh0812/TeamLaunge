#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

// �̰� ��ΰ� �ǵ�����ϴ� Ŭ�����ε�,
// ���� ����ϴ� cpp���Ͽ� �۾��ؾ� �� ���ϰ� ���Ƽ� ���� cpp�� �����صξ���.

// ���� ����� �۾����ε� ���� Ǫ���ߴٱ淡 Ǯ�޾ƾ� �Ǳ� ���ٵ�
// ���� ��� �۾��ߴ��� ��ȣ�ϸ� Ǯ�ް� ���� ���⵵ �ָ����ݾ�
// �׷��ϱ� ���� ���Ͽ� ���ͼ� �ϴٰ� Ǯ�ް� �ߴ����� �߰��� �־ �ٽ� Ǫ���ϴ� ������ �ϸ� �ɰŰ���

// ���� �ݸ������� �����ʿ��� ������ �˴� ���� �ϴ°ɷ� ��������. ��ǻ� 1���浹���� �÷��̱׶��忪��(�ܹ�������)
// ������ �̷��� ������ ���� �ʿ��ҋ����� Ŭ������ ��ȣ������ �׳������ɰ� �ϴ°� ������
// ���� ���� ��Ÿ�ϴ�� �����ص� �ȴٰ� ��

class collision : public gameNode
{
private:
	player*			_pl;
	enemyManager*	_em;
	stageManager*	_sm;
	itemManager*	_im;

	int _itemOrder; //�̰ɷ� ������ ���� ���غ����� ����;

public:
	collision();
	~collision();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void chanhoInit();		void chanhoUpdate();	void chanhoRender();
	void deokhoInit();		void deokhoUpdate();	void deokhoRender();
	void hyunjungInit();	void hyunjungUpdate();	void hyunjungRender();
	void yoonghoInit();		void yoonghoUpdate();	void yoonghoRender();
	void younghanInit();	void younghanUpdate();	void younghanRender();

	void setPlMemoryAddressLink(player* pl)			{ _pl = pl; }
	void setEmMemoryAddressLink(enemyManager* em)	{ _em = em; }
	void setSmMemoryAddressLink(stageManager* sm)	{ _sm = sm; }
	void setImMemoryAddressLink(itemManager* im)	{ _im = im; }
};

