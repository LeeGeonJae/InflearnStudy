#include <iostream>

using namespace std;


int GlobalValue = 0;

void Test()
{
	cout << "���� ������ ���� " << GlobalValue << endl;
	GlobalValue++;
}


int main()
{
	cout << "���� ������ ���� " << GlobalValue << endl;
	GlobalValue++;
	
	Test();

	//��������
	int localValue = 0;


	return 0;
}