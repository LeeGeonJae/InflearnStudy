#include <iostream>
#include "Test1.h"

using namespace std;

// ������ ���� : ��ü ������ ����

// ������ + ����(����, ����)
// ��ü���� = ��ü
// ��ü��? Ǯ���̾�, ����, GameRoom

// Knight�� �����غ���
// - �Ӽ�(������) : hp, attack, location(x, y)
// - ���(����) : Die, Attack, Move

// struct�� ��������δ� �ſ� ����ϴ�
class Knight
{
public:
	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// ��� ����
	int hp;
	int attack;
	int posY;
	int posX;
};

void Move(Knight* knight, int y, int x)
{
	knight->posY = y;
	knight->posX = x;
}

void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posX = 0;
	k1.posY = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 50;
	k2.posX = 1;
	k2.posY = 1;

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	Move(&k1, 2, 2);

	return 0;
}