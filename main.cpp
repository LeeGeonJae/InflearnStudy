#include <iostream>

using namespace std;

// ������ ���� : �ݺ� (Callback)

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

class FindByOwnerId
{
public:
	bool operator()(const Item* item)
	{
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;
};

class FindByRarity
{
public:
	bool operator()(const Item* item)
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity;
};

template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		if (selector(item))
			return item;
	}
}

int main()
{
	// �Լ� ������ + �Լ� ��ü + ���ø�
	// �ݺ� (Callback)

	// ������ ���� �� �̷� �ݹ��� ������ ���� �����Ѵ�
	// ex) MoveTesk �ǽ� ��

	// � ��Ȳ�� �Ͼ�� -> �� ����� ȣ������
	// ex) UI ��ų ��ư�� ������ -> ��ų�� ���� �Լ��� ȣ��

	Item item[10];
	item[3]._ownerId = 100;
	item[8]._rarity = 2;

	FindByOwnerId functor1;
	functor1._ownerId = 100;

	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(item, 10, functor1);
	Item* item2 = FindItem(item, 10, functor2);

	return 0;
}