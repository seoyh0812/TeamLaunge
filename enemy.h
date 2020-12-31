#pragma once
#include "gameNode.h"
#include "progressBar2.h"

enum enemyState
{
	E_IDLE_UP,
	E_IDLE_L,
	E_IDLE_R,
	E_IDLE_DW,
	E_WORK_UP,
	E_WORK_L,
	E_WORK_R,
	E_WORK_DW,
	E_ATK_UP,
	E_ATK_L,
	E_ATK_R,
	E_ATK_DW
};

class enemy : public gameNode
{
private:
	image* _enemy;
	enemyState _enemyState;
	RECT _enemyRc;
	int _eCount, _eIndex;

	progressBar2* _enemyHpBar;
	int _enemyHp, _enemyMaxHp;
	int _enemyPatCount, _enemyPat;
	bool _disappear;

public:

	enemy();
	~enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void render(int x, int y);
	virtual void enemyAnim();
	virtual void enemyMove();
	virtual void onDis();

	inline RECT& getEnemy() { return _enemyRc; }
	inline int& getHp() { return _enemyHp; }
	inline enemyState& getEstate() { return _enemyState; }
	inline bool& getDis() { return _disappear; }

};

