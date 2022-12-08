#include <iostream>

using namespace std;

// ������ ���� : Ÿ�� ��ȯ (������)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // �̷� ���� ������� ���� �������
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [ �ּ� ] -> Heap [ _hp(4) ] 
		Knight* knight = new Knight();

		// �Ͻ������δ� NO
		// ��������δ� OK

		// Stack [ �ּ� ] -> Heap [ _hp(4) ]
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDbId = 1;

		delete knight;
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		// [ [ Item ]    ]
		// [     _damage ]
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		// [ [ Item ]    ]
		// [     _damage ]
		Weapon* weapon = new Weapon();
		
		// �Ͻ������ε� �ȴ�!
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻��׻� �����ؾ� �Ѵ�!
	// �Ͻ������� �� ���� �����ϴ�
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� �� �ϸ� �Ǵ°� �ƴѰ�?

	Item* inventory[5] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 5; i++)
	{
		int randValue = rand() % 2; // 0 ~ 1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ************************** �ſ� �ſ� �ſ� �߿� **************************
	for (int i = 0; i < 5; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;
	}

	// [���]
	// - ������ vs �Ϲ� Ÿ�� : ���̸� ��������
	// - ������ ������ Ÿ�� ��ȯ(ĳ����)�� �� ���� �ſ� �ſ� �����ؾ� �Ѵ�!
	// - �θ�-�ڽ� ���迡�� �θ� Ŭ������ �Ҹ��ڿ��� ����� ���� virtual�� ������!!

	return 0;
}