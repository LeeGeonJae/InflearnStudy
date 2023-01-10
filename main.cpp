#include <iostream>
#include <vector>
#include <list>

using namespace std;

// ������ ���� : list

// vector : ���� �迭
// [              ]

// Node [ data(4), next(4/8) ]
class Node
{
public:
	Node* 	_next;
	Node* 	_prev;
	int 	_data;
};

// ���� / ���� / ����
// list : ���� ����Ʈ

// [1] -> [2] -> [3] -> [4] -> [5] ����
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <-> [ _Myhead end[] ]����
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [1] ����


int main()
{
	// list (���� ����Ʈ)
	// - list�� ���� ����
	// - �߰� ����/���� (GOOD / GOOD)
	// - ó��/�� ����/���� (GOOD / GOOD)
	// - ���� ���� (i��° �����ʹ� ��� �ֽ��ϱ�?) (NO)

	list<int> li;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
		{
			itRemember = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}
	
	//li.push_front(10);
	int size = li.size();
	//li.capacity // �ƿ� ����.

	int first = li.front();
	int last = li.back();

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	//list<int>::iterator it2 = itBegin + 10;

	//list<int>::iterator itTest1 = --itBegin;
	//list<int>::iterator itTest2 = --itEnd;
	//list<int>::iterator itTest3 = ++itEnd;

	//li[3] = 10; // ����

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);
	//li.erase(li.begin());
	//li.pop_front();
	//li.remove(10); // �ش� �� �����ϴ� ��ɵ� �ִ�

	// * ���� ������ �� �ȴ�
	// * �߰� ����/���� ������ (?)

	// 50�� �ε����� �ִ� �����͸� ����

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; ++i)
		++it;

	li.erase(itRemember);

	return 0;
}