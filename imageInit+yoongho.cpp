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

	IMAGEMANAGER->addImage("�ƾ��������", "image/ui/cutsceneback.bmp", 1538, 410, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ƾ�ĳ��", "image/ui/cutscenefront.bmp", 1024, 410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ƾ����", "image/ui/cutscenebackground.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ƾ����â", "image/ui/cutscenedialogback.bmp", 1024, 204, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ƾ����1", "image/ui/cutscenedialog1.bmp", 664, 28, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ƾ����2", "image/ui/cutscenedialog2.bmp", 818, 26, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ƾ����3", "image/ui/cutscenedialog3.bmp", 459, 27, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ƾ�����", "image/ui/cutscenered.bmp", 75, 83, false, RGB(0, 0, 0));

	IMAGEMANAGER->addFrameImage("�����϶�", "image/ui/playericon.bmp", 126, 72, 2, 1, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ü�¹�", "image/ui/bossbar.bmp", 576, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�׳��ؽ�Ʈ", "image/ui/text.bmp", 864, 96, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�����ؽ�Ʈ", "image/ui/bosstext.bmp", 168, 24, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�÷��̾�����", "image/player/dead.bmp", 1665, 588, 5, 2, true, RGB(255, 0, 255));

}