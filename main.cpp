#include <iostream>

using namespace std;

// 오늘의 주제 : 호출 스택

// 함수 선언
void Func1();
void Func2(int a, int b);
void Func3(float a);

int main()
{
	cout << "main" << endl;
	Func1();

	return 0;
}

void Func3(float a)
{
	cout << "Func3" << endl;

	// push 2
	// push 1
	// call Func2
	Func2(1, 2);
}



void Func1()
{
	cout << "Func1" << endl;

	Func2(1, 2);
}