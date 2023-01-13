#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// ������ ���� : ���� ����

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
	// ������ (override)
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

	// �����ε� (overloading) : �Լ� �̸��� ����
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