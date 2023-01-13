#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// ������ ���� : �˰���


int main()
{
	// �ڷᱸ�� (�����͸� �����ϴ� ����)
	// �˰��� (�����͸� ��� ����� ���ΰ�?)

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

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			// ��ã����
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
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
			// ��ã����
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
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

		struct IsOdd
		{
			bool operator()(int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());

		// ��� �����Ͱ� Ȧ���Դϱ�?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
	}

	// 04) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		for (vector<int>::iterator findit = v.begin(); findit != v.end(); ++findit)
		{
			cout << *findit << " 3��� �ϱ� �� : ";
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

		// ��𼭺��� ������ ������ ���ּ���.
		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Ȧ���� �����͸� �ϰ� ����
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