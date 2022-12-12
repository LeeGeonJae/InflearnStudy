#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	// push push
	_target2->KillMe();

	//_target2->_hp = 0;

	// [ аж╪р ] -> [ [monsterId][hp][defence] ]
	//(*_target2)._hp = 0;
}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}