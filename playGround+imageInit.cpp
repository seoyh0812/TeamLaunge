#include "stdafx.h"
#include "playGround.h"

// ���� �̹����Ŵ��� �߰��� ���⼭

void playGround::imageInit()
{
	// �ʰ���
	IMAGEMANAGER->addImage("��", "image/AllStage_front.bmp", 4848, 2304, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("â�����", "image/ui/airstageback.bmp", 1024, 704, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���", "image/ui/column.bmp", 77, 769, false, RGB(255, 0, 255));
}