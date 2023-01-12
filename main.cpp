#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

using namespace std;

// 오늘의 주제 : set, multimap, multiset

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// 01) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
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
				cout << *it << " 찾음" << endl;
			}
		}
	}

	// 02) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
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
				cout << *it << " 찾음" << endl;
			}
		}
	}

	// 03) 홀수인 숫자의 개수는? (count)
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

		cout << "홀수인 숫자의 갯수 : " << count << endl;
	}

	// 04) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			cout << *findit << " 3배수 하기 후 : ";
			(*findit) = (*findit) * 3;
			cout << (*findit) << endl;
		}
	}

	return 0;
}