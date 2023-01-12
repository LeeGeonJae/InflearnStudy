#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>

using namespace std;

// ������ ���� : map

class Player
{
public:
	Player() : _playerId(0)
	{

	}

	Player(int playerId) : _playerId(playerId)
	{

	}

public:
	int _playerId;
};

template<typename T1, typename T2>
struct Pair
{
	T1 t1;
	T2 t2;
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// ���� �����̳�

	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���

	class Node
	{
	public:
		Node* _left;
		Node* _right;
		// DATA
		int _key;
		Player* _value;
	};

	// (Key, Value)
	map<int, int> m;

	//pair<map<int, int>::iterator, bool> ok;
	//ok = m.insert(make_pair(1, 100));
	//ok = m.insert(make_pair(1, 200));

	//ok.first;
	//ok.second;

	// 10����
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5���� ����
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		//m.erase(m.begin(), m.end());

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 1���� Player ã�� �ʹ�!
	// A) �ſ� ������ ã�� �� ����



	// map ��ȸ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = *it;
		int key = (*it).first;
		int value = it->second;

		//cout << key << " " << value << endl;
	}

	// ������ �߰�, ������ ����

	map<int, int>::iterator findit = m.find(10000);
	if (findit != m.end())
	{
		findit->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// ������ �߰�, ������ ���� v2
	m[5] = 500;

	m.clear();

	// [] ������ ����� �� ����
	// ������ ���� �ʴ��� (Key/Value) ������ �����Ͱ� �߰��ȴ�
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}

	// �ְ�		(insert, [])
	// ����		(erase)
	// ã��		(find, [])
	// �ݺ���	(map, iterator) (*it) pair<key, value>&

	return 0;
}