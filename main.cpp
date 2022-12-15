#include <iostream>

using namespace std;

// ������ ���� : �Լ� ������

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0) , _rerity(0), _ownerId(0)
	{

	}

public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rerity; // ��͵�
	int _ownerId; // ������ ID
};

typedef bool(ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item, value))
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rerity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// �ٱ��� �ּ�
	// pointer[ �ּ� ] -> �ּ�[    ]

	typedef int DATA;
	
	// 1) ������			*
	// 2) ���� �̸�		pointer
	// 3) ������ Ÿ��		int
	DATA* pointer = &a;

	// �Լ�
	typedef int(FUNC_TYPE)(int, int);
	//using FUNC_TYPE = int(int, int); // ��� C++������ �̷��Ե� ����Ѵ�

	// 1) ������			*
	// 2) ���� �̸�		fn
	// 3) ������ Ÿ��		�Լ� (���ڴ� int, int ��ȯ�� int)
	FUNC_TYPE* fn;

	// �Լ� ������
	fn = Sub;

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = fn(1, 2); // �⺻ ����
	cout << result << endl;

	int result2 = (*fn)(1, 2); // �Լ� �����ʹ� *(���� ������) �ٿ��� �Լ� �ּ�!
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rerity = 2; // RARE
	FindItem(items, 10, IsRareItem, 100); // �Լ� �����ʹ� �ٸ� �Լ� ���ڷ� �Ѱ��ְ� ���� �� ����Ѵ�

	return 0;
}