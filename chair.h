#pragma once
#include "object.h"

class chair :public object
{
private:

	image* _img;
	RECT _chairRect;
	RECT _chairShadow;


public:
	chair();
	~chair();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void shadowRender(RECT rc);

	image* getChairImg() { return _img; }

	RECT getShadow() { return _chairShadow; }
	RECT getChairRect() { return _chairRect; }

};

