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

	v.reserve(1000);
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	// - �߰� ����/���� (BAD)
	// - ó��/�� ����/���� (BAD / GOOD)
	// - ���� ���� (Random Access)

	// vector = ���� �迭 = �������� Ŀ���� �迭 = �迭
	// ���Ұ� �ϳ��� �޸� ��Ͽ� �����ϰ� ����ȴ� !!!

	// [                         ]
	// [0] [1] [2] [3] [4] [5] []

	v.push_back(1);
	v.pop_back();

	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	//vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	// ��- ��ĵ�� �ϸ鼭, 3�̶�� �����Ͱ� ������ �ϰ� �����ϰ� �ʹ�

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