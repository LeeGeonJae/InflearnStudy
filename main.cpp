#include <iostream>

using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class RabbitPet : public Pet
{

};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	
	// ���� ������
	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}

	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{

	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));
		return *this;
	}

	~Knight()
	{

	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{

	Knight knight; // �⺻ ������
	knight._hp = 200;

	cout << "------------ ���� ������ ------------" << endl;
	Knight knight2 = knight; // ���� ������
	//Knight knight3(knight);

	cout << "------------ ���� ���� ������ ------------" << endl;
	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �� ������ָ� �����Ϸ� '�Ͻ�������' ������ش�

	// �߰� ���) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �����ϼ���~ ���� ���� �Ѿ���? << NO

	// [ ���� ���� Shallow Copy ]
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight [ hp 0x1000 ]		-> Heap 0x1000 Pet [  ]
	// Stack : Knight2 [ hp 0x1000 ]
	// Stack : Knight3 [ hp 0x1000 ]

	// [ ���� ���� Deep Copy ]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش� (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü ����Ű�� ���°� ��
	// Stack : Knight [ hp 0x1000 ]		-> Heap 0x1000 Pet [  ]
	// Stack : Knight2 [ hp 0x2000 ]	-> Heap 0x2000 Pet [  ]
	// Stack : Knight3 [ hp 0x3000 ]	-> Heap 0x3000 Pet [  ]

	// ����)
	// - �Ͻ��� ���� ������ Step;
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ��� Shallow Copy)
	// - ����� ���� ������ Step;
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ��

	// - �Ͻ��� ���� ���� ������ Steps
	// - ����� ���� ���� ������ Steps

	return 0;
}