#pragma once

//#include "Monster.h"

// class�� ���赵
class Player
{
public:

	void KillMonster();
	void KillMonster2();


public:
	int _hp;
	int _attack;

	//Monster _target;
	class Monster* _target2;

	Player* _target;
};