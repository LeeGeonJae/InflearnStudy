#include <iostream>
#include <vector>

using namespace std;

// 오늘의 주제 : vector


int main()
{
	// STL (Standard Tamplate Libary)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이터(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 동적 배열
	// 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// 1) 여유분은 얼만큼이 적당할까?
	// 2) 증설을 얼만큼 해야 할까?
	// 3) 기존의 데이터를 어떻게 처리할까?

	int arr[100];

	vector<int> v(1000, 0);
	vector<int> v2 = v;

	// [                 ]
	//v.resize(1000);
	cout << v.size() << " " << v.capacity() << endl;
	// size(실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7 ...
	
	//v.reserve(1000);
	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 42 63

	for (int i = 0; i < 1001; i++)
	{
		//v[i] = 100;
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	vector<int>().swap(v); // () : 깡통이니까 메모리를 날려주고 이 과정이 끝나면 깡통도 메모리가 없어진다
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}