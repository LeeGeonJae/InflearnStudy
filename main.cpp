#include <iostream>
#include <vector>

using namespace std;

// 오늘의 주제 : vector


int main()
{
	// 컨테이터(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 반복자(iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	v.reserve(1000);
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	// - 중간 삽입/삭제 (BAD)
	// - 처음/끝 삽입/삭제 (BAD / GOOD)
	// - 임의 접근 (Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다 !!!

	// [                         ]
	// [0] [1] [2] [3] [4] [5] []

	v.push_back(1);
	v.pop_back();

	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	//vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	// 쭉- 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
			it = v.erase(it);
		else
		{
			++it;
		}
	}

	return 0;
}