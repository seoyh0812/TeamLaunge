#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex64_vc.lib")

using namespace FMOD;

#define SOUNDBUFFER 50
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER


class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**>			arrSounds;
	typedef map<string, Sound**>::iterator	arrSoundsIter;

	typedef map<string, Channel**>				arrChannels;
	typedef map<string, Channel**>::iterator	arrChannelIter;

private:
	System*			_system;
	Sound**			_sound;
	Channel**		_channel;
	float _volume;

	arrSounds		_mTotalSounds;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	//   ���� �߰��Լ�(Ű ��, �������ϸ�, ���orȿ����, �����Ҳ���)
	void addSound(string keyName, string soundName, bool bgm, bool loop);

	//                             0.0f ~ 1.0f -> 0 ~ 255
	void play(string keyName, float volume);
	void play(string keyName);
	void setVolume(float volume);
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	//ȣ������ ���� ������
	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);
};

