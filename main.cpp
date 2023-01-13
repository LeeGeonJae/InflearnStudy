#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 중괄호 초기화 { }

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	// TODO
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// NullPtr 구현

class NullPtr
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const; // 주소값 &을 막는다
};

const NullPtr _NullPtr;

int main()
{
	int* ptr = NULL; // 0 NULL

	// 1) 오동작
	Test(0);
	Test(NULL);
	Test(_NullPtr);

	// 2) 가독성
	auto knight = FindKnight();
	if (knight == _NullPtr)
	{

	}

	void (Knight::* memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _NullPtr)
	{

	}

	nullptr_t whoami = nullptr;

	return 0;
}