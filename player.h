#pragma once
#include "gameNode.h"
#include "attack.h"

class attack;

class enemyManager;

class STATE; // ��ȣ������ ���漱�� ������

enum State {
	IDLE,
	CIDLEANIMATION,
	JUMP,
	WALK,
	RUN,
    SLIDE,
    TACKLE,
    JUMPATTACK,
    HIT,
	COMBO1,
	COMBO11,
	COMBO12,
	COMBO13,
    COMBO21,
    COMBO22,
    COMBO23,
	GRAB,
	GRABSWING,
    WINDMILL
};

class player :
	public gameNode
{
private:
	image* playerImage; //�÷��̾� �̹�����
	float _flyX; float _flyY;		// �����ϸ� ��ü��Ż�ϵ��� ����
	RECT _flyRc;
	float _groundX; float _groundY; // ���� �ٴ�RC
	RECT _groundRc;
	RECT _shadow;					//9���� rc
	bool _left;						// ������ ���� �ִ���
	State _enumState;
	STATE* _statePattern;
	char _str[128];
	float _currentHP;
	float _maxHP;
	attack* _attack;
	int _count, _index; //������ �̹��� ����� ī��Ʈ, �ε���.
    float _jumpPower; // ���� �Ŀ�
    bool _isHit;        //�¾Ҵ���, ��Ҵ��� �ҹٴ�
    bool _isGrab;

	// ############ Ŀ�ǵ� �Է� ���� ����(���, Ư����) #############
	int _directionChanged;		// �¿찡 ��� �ٲ������ ī��Ʈ(Ŀ�ǵ�)
	int _directionChangeCount;	// ī��Ʈüũ�ؼ� ����
	int _dirMemory;				// ���� ���(�뽬��)
	int _dirMemoryCount;		// ī��Ʈüũ�ؼ� ����

	enemyManager* _em;

public:
	player() {};
	~player() {};
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
	void stateUpdate();
	void stateRender();
	RECT getGroundRc() { return _groundRc; }
	RECT getFlyRc() { return _flyRc; }
    RECT getShadow() { return _shadow; }
	float& getGroundX() { return _groundX; }float& getGroundY() { return _groundY; }
	float& getFlyX() { return _flyX; }		float& getFlyY() { return _flyY; }
	bool& getLeft() { return _left; }
	State& getEnumState() { return _enumState; }
	void plusDirectionChanged() { ++_directionChanged; }
    int& getDirectionChanged() {return _directionChanged; }
	int& getDirMemory() {return _dirMemory;}
	void setLinkEnemy(enemyManager* em) { _em = em; }
	attack* getAttack() { return _attack; }
	int& getIndex() { return _index; }
    float& getJumpPower() { return _jumpPower; }
    bool& getIsHit() { return _isHit; }
    bool& getIsGrab() { return _isGrab; }
    float& getPlHP() { return _currentHP; }
    void getDamage(int x) { _currentHP -= x; }
};

