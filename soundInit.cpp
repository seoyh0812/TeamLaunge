#include "stdafx.h"
#include "playGround.h"

void playGround::soundInit()
{//��ݷ�
	SOUNDMANAGER->addSound("����Ʈ��", "sound/����Ʈ��.mp3", true, true);
	SOUNDMANAGER->addSound("���κ��", "sound/bgm����.wav", true, true);
	SOUNDMANAGER->addSound("�������", "sound/bgm����.wav", true, true);

	//ȿ������
	SOUNDMANAGER->addSound("����", "sound/���ӳ�.wav", false, false);
	SOUNDMANAGER->addSound("����", "sound/���γ���.mp3", false, false);
	SOUNDMANAGER->addSound("���� �̵�", "sound/����Ʈ �̵�.wav", false, false);
	SOUNDMANAGER->addSound("���� ����", "sound/����2.wav", false, false);
	
	SOUNDMANAGER->addSound("������1", "sound/�� ����01.wav", false, false);
	SOUNDMANAGER->addSound("������2", "sound/�� ����02.wav", false, false);
	SOUNDMANAGER->addSound("��������", "sound/��������.wav", false, false);
	SOUNDMANAGER->addSound("������Ҹ�", "sound/������Ҹ�.wav", false, false);

	SOUNDMANAGER->addSound("��ź", "sound/��ź.wav", false, false);
	SOUNDMANAGER->addSound("������", "sound/�� ������.wav", false, false);
	SOUNDMANAGER->addSound("��������μ��¼Ҹ�", "sound/��������μ��¼Ҹ�.wav", false, false);
	SOUNDMANAGER->addSound("���ںμ��¼Ҹ�", "sound/���ںμ��� �Ҹ�.wav", false, false);
	SOUNDMANAGER->addSound("�Դ¼Ҹ�", "sound/���ĸԱ�.wav", false, false);

	SOUNDMANAGER->addSound("Ÿ��1", "sound/Ÿ����01.wav", false, false);
	SOUNDMANAGER->addSound("Ÿ��2", "sound/Ÿ����02.wav", false, false);
	SOUNDMANAGER->addSound("Ÿ��3", "sound/Ÿ����03.wav", false, false);
	SOUNDMANAGER->addSound("Ÿ��4", "sound/Ÿ����04.wav", false, false);
	SOUNDMANAGER->addSound("������", "sound/������.wav", false, false);
	SOUNDMANAGER->addSound("����1", "sound/����01.wav", false, false);
	SOUNDMANAGER->addSound("����2", "sound/����02.wav", false, false);

}