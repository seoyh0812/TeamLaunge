#include "stdafx.h"
#include "playGround.h"

// ���� �̹����Ŵ��� �߰��� ���⼭

void playGround::imageInitDeokho()
{
	IMAGEMANAGER->addImage("��", "image/item_bmp/ball_basic.bmp", 47, 45, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��׷�����", "image/item_bmp/ball_strach.bmp", 98, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ź", "image/item_bmp/bomb_angle.bmp", 560, 70, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������Ʈ", "image/item_bmp/bombEffect.bmp", 1035, 171, 9, 1, true, RGB(255, 0, 255));
	EFFECTMANAGER->addEffect("����", "image/item_bmp/bombEffect.bmp", 1035, 171, 115, 171, 3, 0.1f, 20);
}