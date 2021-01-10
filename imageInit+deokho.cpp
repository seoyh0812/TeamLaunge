#include "stdafx.h"
#include "playGround.h"
#define MAGENTA RGB(255,0,255)
// 각종 이미지매니저 추가는 여기서

void playGround::imageInitDeokho()
{
	IMAGEMANAGER->addImage("공", "image/item_bmp/ball_basic.bmp", 47, 45, true, MAGENTA);
	IMAGEMANAGER->addImage("찌그러진공", "image/item_bmp/ball_strach.bmp", 98, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피자", "image/item_bmp/pizza.bmp", 104, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("폭탄", "image/item_bmp/bomb_angle.bmp", 560, 70, 8, 1, true, RGB(255, 0, 255));
	EFFECTMANAGER->addEffect("폭발", "image/item_bmp/bombEffect.bmp", 1035, 171, 115, 171, 3, 0.1f, 20);
}