#pragma once
#include "enemy.h"

// 클래스명 맘에 안들면 없애도 됨. 그저 예시일 뿐이니까..

class minion :	public enemy
{
private:
	
public:
	minion();
	~minion();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
};
