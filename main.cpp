#include <iostream>
#include "Player.h"

using namespace std;

// ������ ���� : ���漱��


int main()
{
	// Player�� �� ����Ʈ?
	// int 2�� = 2 * 4 = 8����Ʈ + sizeof(Player*) = 12����Ʈ


	// Player [ hp ] [ attack ] [ �ּ� ]
	// sizeof(Monster*) = 4 or 8

	Player p1; // �������� (Stack)

	Player* p2 = new Player(); // �����Ҵ� (Heap)
	
	p1._target = p2;

	return 0;
}