#include <iostream>
#include <vector>

using namespace std;

// ������ ���� : vector


int main()
{
	// STL (Standard Tamplate Libary)
	// ���α׷����� �� �ʿ��� �ڷᱸ��/�˰������
	// ���ø����� �����ϴ� ���̺귯��

	// ��������(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)

	// vector (���� �迭)
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/�� ����/����
	// - ���� ����

	// ���� �迭
	// �߿��� ���� -> � ������ �ηȱ淡 �迭�� '����������' ����� ���ΰ�?

	// 1) (�������� �ΰ�) �޸𸮸� �Ҵ��Ѵ�
	// 2) �����б��� �� á����, �޸𸮸� �����Ѵ�

	// 1) �������� ��ŭ�� �����ұ�?
	// 2) ������ ��ŭ �ؾ� �ұ�?
	// 3) ������ �����͸� ��� ó���ұ�?

	int arr[100];

	vector<int> v(1000, 0);
	vector<int> v2 = v;

	// [                 ]
	//v.resize(1000);
	cout << v.size() << " " << v.capacity() << endl;
	// size(���� ��� ������ ����)
	// 1 2 3 4 5 6 7 ...
	
	//v.reserve(1000);
	// capacity (�������� ������ �뷮 ����)
	// 1 2 3 4 6 9 13 19 28 42 63

	for (int i = 0; i < 1001; i++)
	{
		//v[i] = 100;
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	vector<int>().swap(v); // () : �����̴ϱ� �޸𸮸� �����ְ� �� ������ ������ ���뵵 �޸𸮰� ��������
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}