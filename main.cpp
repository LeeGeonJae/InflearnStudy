#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 알고리즘


int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)

	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if

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

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			// 못찾았음
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
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

		struct CanDivideBy11
		{
			bool operator()(int n)
			{
				return (n % 11) == 0;
			}
		};

		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		if (itFind == v.end())
		{
			// 못찾았음
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
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

		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수입니까?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
	}

	// 04) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			cout << *findit << " 3배수 하기 후 : ";
			(*findit) = (*findit) * 3;
			cout << (*findit) << endl;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n = n * 3;
			}
		};

		// 어디서부터 어디까지 무엇을 해주세요.
		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// 홀수인 데이터를 일괄 삭제
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		/*template <class ForwardIt, class UnaryPredicate>
		ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) 
		{
			first = std::find_if(first, last, p);
			if (first != last)
				for (ForwardIt i = first; ++i != last;)
					if (!p(*i)) *first++ = std::move(*i);
			return first;
		}*/

		// 1 4 3 5 8 2
		// 4 8 2 5 8 2
		
		// 4 8 2 5 8 2

		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());
	}

	return 0;
}