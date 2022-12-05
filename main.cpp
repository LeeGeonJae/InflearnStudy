#include <iostream>

using namespace std;

// ������ ���� : ���м�

// ��ü���� (OOP Object Oriented Programing)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ������(Polymorphism = Poly + morph) = ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�
// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����
// - �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dynamic Binding) : ���� ������ ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ� (virtual function)

// �׷��� ���� ��ü�� ��� Ÿ������ ��� �˰� �˾Ƽ� �����Լ��� ȣ�����ذɱ�?
// - ���� �Լ� ���̺� (vftable)

// .vftable [] 4����Ʈ(32) 8����Ʈ(64)
// [VMove] [VDie] 

// ���� ���� �Լ� : ������ ���� '�������̽�'�� �����ϴ� �뵵�� ����ϰ� ���� ���
// �߻� Ŭ���� : ���� ���� �Լ��� 1�� �̻� ���ԵǸ� �ٷ� �߻� Ŭ������ ����
// - ���������� ��ü�� ���� �� ���� ��

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }
	//void Move(int a) { cout << "Move Player (int) !" << endl; }

	virtual void VMove() { cout << "VMove Player !" << endl; }
	virtual void VDie() { cout << "VDie Player !" << endl; }

	// ���� ���� �Լ�
	virtual void Vattack() = 0;

public:
	int _hp;
};

class Knight : public Player
{
public:

	Knight()
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight Player !" << endl; }
	
	// ���� �Լ��� �����Ǹ� �ϴ��� ���� �Լ���!
	virtual void VMove() { cout << "VMove Knight !" << endl; }
	virtual void VDie() { cout << "VDie Knight !" << endl; }

	virtual void Vattack() { cout << "Vattack Knight !" << endl; }

public:
	int _stamina;
};

// [ [ Player] ]
// [   Knight  ]

void MovePlayer(Player* player)
{
	player->VMove();
	player->VDie();
}

class Mage : public Player
{

public:
	int _mp;
};

int main()
{
	// Player p;		// �߻� Ŭ������ ��ü ������ �Ұ���
	// MovePlayer(&p);	// �÷��̾�� �÷��̾��? YES
	// MoveKnight(&p);	// �÷��̾�� ����? NO


	Knight k;
	// MoveKnight(&k); // ���� ����? YES
	MovePlayer(&k); // ���� �÷��̾��? YES

	return 0;
}