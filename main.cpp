#include <iostream>
using namespace std;

// ������ ���� : ������ �ǽ�

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
	cout << "�κ� �����߽��ϴ�" << '\n';

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [�Ű�����][ret][��������temp(c,c,c), player(b,b,b)] [�Ű�����(&temp)][ret][��������(ret(100, 10, 2))]
	// -> player(b,b,b) = StatInfo temp(100, 10, 2)
	// -> player (100, 10, 2)
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	// [�Ű�����][ret][��������monster(b,b,b)] [�Ű�����(&monster)][ret][��������]
	// -> monster(40, 8, 1)
	CreateMonster(&monster);

	// ������1)
	// ����ü���� ������ �� ���� ���� ��������?
	// 
	player = monster;

	// -> player.hp = monster.hp;
	// -> player.attack = monster.attack;
	// -> player.defence = monster.defence;
}


StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "�÷��̾� ����" << '\n';

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << '\n';

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}