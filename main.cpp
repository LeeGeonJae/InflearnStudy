#include <iostream>
#include <vector>

using namespace std;

// ������ ���� : vector


int main()
{
	// ��������(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)

	// vector (���� �迭)
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/�� ����/����
	// - ���� ����

	// �ݺ���(iterator) : �����Ϳ� ������ ����. �����̳��� ����(������)�� ����Ű��, ����/���� ���ҷ� �̵� ����
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;

	ptr++;
	++ptr;
	it++;
	++it;

	it += 2;
	it = it - 2;

	// �� �����غ��̴µ�?
	// �ٸ� �����̳ʴ� v[i]�� ���� �ε��� ������ �ȵ� ���� ����
	// iterator�� vector�� �ƴ϶�, �ٸ� �����̳ʿ��� ���������� �ִ� ����
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
	cout << "iterator" << endl << endl;

	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}
	cout << "Ptr" << endl << endl;

	// const int*;
	//vector<int>::const_iterator cit1 = v.cbegin();
	//*cit1 = 100;

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it) << endl;
	}
	cout << "reverse_iterator" << endl;

	return 0;
}