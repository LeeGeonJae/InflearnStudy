#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

using namespace std;

// ������ ���� : set, multimap, multiset

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// 01) number��� ���ڰ� ���Ϳ� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		// TODO
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			if ((*findit) == number)
			{
				it = findit;
				found = true;
				cout << *it << " ã��" << endl;
			}
		}
	}

	// 02) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		// TODO
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			if ((*findit) % 11 == 0 && (*findit) > 10)
			{
				it = findit;
				found = true;
				cout << *it << " ã��" << endl;
			}
		}
	}

	// 03) Ȧ���� ������ ������? (count)
	{
		int count = 0;

		// TODO
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			if ((*findit) % 2 != 0)
			{
				count++;
			}
		}

		cout << "Ȧ���� ������ ���� : " << count << endl;
	}

	// 04) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			cout << *findit << " 3��� �ϱ� �� : ";
			(*findit) = (*findit) * 3;
			cout << (*findit) << endl;
		}
	}

	return 0;
}