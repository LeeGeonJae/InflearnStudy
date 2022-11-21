#include <iostream>
using namespace std;

// ������ ���� : Text RPG

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
		cout << "�κ� �����߽��ϴ�." << endl;
		cout << "--------------------" << endl;

		// �÷��̾� ���� ����
		SelectPlayer();

		cout << "--------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
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
		cout << "������ ����ּ���." << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;
		cout << "> ";

		cin >> playerType;

		switch (playerType)
		{
		case PT_Knight:
			cout << "��� ������...!" << endl;
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