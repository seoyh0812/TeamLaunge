#include "stdafx.h"
#include "playGround.h"

// ���� �̹����Ŵ��� �߰��� ���⼭

void playGround::imageInitYoongho()
{
	IMAGEMANAGER->addImage("��", "image/AllStage_front.bmp", 4848, 2304, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("â�����", "image/ui/airstageback.bmp", 1024, 704, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���", "image/ui/column.bmp", 77, 769, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "image/ui/selectbackground.bmp", 957, 674, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����Ŀ��", "image/ui/selectcursor.bmp", 96, 96, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ĳ��", "image/ui/selectcharacter.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "image/ui/selectred.bmp", 480, 404, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ʷϼ���", "image/ui/numbertime.bmp", 450, 45, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�Ͼ����", "image/ui/number.bmp", 240, 24, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������", "image/ui/numberscore.bmp", 240, 24, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�ü�¹�", "image/ui/hpbar.bmp", 132, 18, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�ui", "image/ui/playerui.bmp", 213, 102, true, RGB(255, 0, 255));
}