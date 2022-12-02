#include <iostream>
#include "Test1.h"

using namespace std;

// 오늘의 주제 : 객체 지향의 시작

// 데이터 + 가공(로직, 동작)
// 객체지향 = 객체
// 객체란? 풀레이어, 몬스터, GameRoom

// Knight를 설계해보자
// - 속성(데이터) : hp, attack, location(x, y)
// - 기능(동작) : Die, Attack, Move

// struct와 기능적으로는 매우 흡사하다
class Knight
{
public:
	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	
	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
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