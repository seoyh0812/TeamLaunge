#pragma once
#include "STATE.h"


//콤보 1-2(이동방향을 설정하지 않은 콤보)입니다.
class player;

class combo12 : public STATE
{
private:
public:

	void EnterState();
	void updateState();
	void ExitState();

};

