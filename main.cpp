#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>

using namespace std;

// 오늘의 주제 : map

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

	// 연관 컨테이너

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

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

	// 10만명
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		//m.erase(m.begin(), m.end());

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음



	// map 순회
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = *it;
		int key = (*it).first;
		int value = it->second;

		//cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정

	map<int, int>::iterator findit = m.find(10000);
	if (findit != m.end())
	{
		findit->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// 없으면 추가, 있으면 수정 v2
	m[5] = 500;

	m.clear();

	// [] 연산자 사용할 때 주의
	// 대입을 하지 않더라도 (Key/Value) 형태의 데이터가 추가된다
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}

	// 넣고		(insert, [])
	// 빼고		(erase)
	// 찾고		(find, [])
	// 반복자	(map, iterator) (*it) pair<key, value>&

	return 0;
}