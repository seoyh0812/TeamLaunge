#pragma once
#include "item.h"
class baseball :	public item
{
private:

public:
	baseball();
	~baseball();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
};

