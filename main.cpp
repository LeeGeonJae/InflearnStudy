#include <iostream>
using namespace std;

// 오늘의 주제 : Text RPG

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};


int playerType;
int hp;
int attack;
int defence;


void EnterLobby();
void SelectPlayer();

int main()
{

	return 0;
}

void EnterLobby()
{
	int input;

	while (0)
	{
		cout << "--------------------" << endl;
		cout << "로비에 입장했습니다." << endl;
		cout << "--------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "--------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "--------------------" << endl;

		cin >> input;
	}

	if (input == 1)
	{
		EnterField();
	}
	else
	{
		return;
	}
}

void SelectPlayer()
{
	while (0)
	{
		cout << "--------------------" << endl;
		cout << "직업을 골라주세요." << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> playerType;

		switch (playerType)
		{
		case PT_Knight:
			cout << "기사 생성중...!" << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			break;
		case PT_Archer:
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		case PT_Mage:
			hp = 80;
			attack = 20;
			defence = 0;
			break;
		}

	}

}