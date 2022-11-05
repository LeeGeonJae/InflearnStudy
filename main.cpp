#include <iostream>

using namespace std;


int GlobalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 " << GlobalValue << endl;
	GlobalValue++;
}


int main()
{
	cout << "전역 변수의 값은 " << GlobalValue << endl;
	GlobalValue++;
	
	Test();

	//지역변수
	int localValue = 0;


	return 0;
}