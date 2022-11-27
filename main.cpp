#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습

struct StatInfo
{
	int hp; // 0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);

int main()
{
	EnterLobby();
	return 0;

}

void EnterLobby()
{
	cout << "로비에 입장했습니다" << '\n';

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][ret][지역변수temp(c,c,c), player(b,b,b)] [매개변수(&temp)][ret][지역변수(ret(100, 10, 2))]
	// -> player(b,b,b) = StatInfo temp(100, 10, 2)
	// -> player (100, 10, 2)
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	// [매개변수][ret][지역변수monster(b,b,b)] [매개변수(&monster)][ret][지역변수]
	// -> monster(40, 8, 1)
	CreateMonster(&monster);

	// 번외편1)
	// 구조체끼리 복사할 떄 무슨 일이 벌어질까?
	// 
	player = monster;

	// -> player.hp = monster.hp;
	// -> player.attack = monster.attack;
	// -> player.defence = monster.defence;
}


StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << '\n';

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << '\n';

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}