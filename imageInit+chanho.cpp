#include "stdafx.h"
#include "playGround.h"

// ���� �̹����Ŵ��� �߰��� ���⼭

void playGround::imageInitChanho()
{
	//�̰Ŵ� ����. yoongho�� �س����� ������ ��.
	//IMAGEMANAGER->addImage("��", "image/AllStage_front.bmp", 4848, 2304, true, RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("�÷��̾���", "image/player/idle.bmp", 240, 462, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾�����", "image/player/cidleAnimation.bmp", 792, 255, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾��̵�", "image/player/move.bmp", 1368, 522, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾���", "image/player/dash.bmp", 768, 480, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�÷��̾���̵�", "image/player/slide.bmp", 306, 462, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�÷��̾���Ŭ", "image/player/tackle.bmp", 192, 444, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾�����", "image/player/jump.bmp", 231, 498, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����", "image/player/attack1.bmp", 1104, 426, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����1-1", "image/player/attack1-1.bmp", 480, 444, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����1-2", "image/player/attack1-2.bmp", 732, 618, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����1-3", "image/player/attack1-3.bmp", 660, 522, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����2-1", "image/player/attack2-1.bmp", 576, 534, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����2-2", "image/player/attack2-2.bmp", 570, 456, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�÷��̾����2-3", "image/player/attack2-3.bmp", 1161, 426, 3, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�÷��̾���������", "image/player/jumpAttack.bmp", 588, 750, 2, 2, true, RGB(255, 0, 255));
}