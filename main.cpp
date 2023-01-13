#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 우측 참조

class Creature
{
public:
	
};

class Player : public Creature
{
public:
	virtual void Attack() final
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// 재정의 (override)
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

	// 오버로딩 (overloading) : 함수 이름의 재사용
	void Attack(int a)
	{

	}

private:
	int _stamina = 100;
};

int main()
{
	Player* player = new Knight();

	player->Attack();

	return 0;
}