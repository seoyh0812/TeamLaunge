#pragma once
#include "gameNode.h"

class STATE; // ��ȣ������ ���漱�� ������

enum State {
	IDLE,
	JUMP,
	WALK,
	RUN
};

class player :
	public gameNode
{
private:
	float _flyX; float _flyY;		// �����ϸ� ��ü��Ż�ϵ��� ����
	RECT _flyRc;
	float _groundX; float _groundY; // ���� �ٴ�RC
	RECT _groundRc;
	bool _left;						// ������ ���� �ִ���
	State _enumState;
	STATE* _statePattern;
	char _str[128];
	float _currentHP;
	float _maxHP;

	// ############ Ŀ�ǵ� �Է� ���� ����(���, Ư����) #############
	int _directionChanged;		// �¿찡 ��� �ٲ������ ī��Ʈ(Ŀ�ǵ�)
	int _directionChangeCount;	// ī��Ʈüũ�ؼ� ����
	int _dirMemory;				// ���� ���(�뽬��)
	int _dirMemoryCount;		// ī��Ʈüũ�ؼ� ����

public:
	player();
	~player();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void minusDirectionChanged();

	void playerRender();
	// �÷��̾� ���������� ���� ������ �ϰ�����
	// ���⿣ z���� ������ ������� �÷��̾� ĳ����'��' �׷��ִ� ��
	// �׷��� �������� �и��� ����

	// �������� �ϸ� ���� ��ģ���� �������µ���. â���̰͵� �þ��µ� ��û ������
	// ���⼭ ���� �����ϴ°ͺ��� ���°�ü���� ������ �Ǳ� ������..
	void setState(State state);
	RECT getGroundRc() { return _groundRc; }
	RECT getFlyRc() { return _flyRc; }
	float& getGroundX() { return _groundX; }float& getGroundY() { return _groundY; }
	float& getFlyX() { return _flyX; }		float& getFlyY() { return _flyY; }
	bool& getLeft() { return _left; }
	State& getEnumState() { return _enumState; }
	void plusDirectionChanged() { ++_directionChanged; }
	int& getDirMemory() {return _dirMemory;}
};
