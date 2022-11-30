#include <iostream>

using namespace std;

// ������ ���� : �ζ� ��ȣ ������

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int* numbers, int count)
{
	for (int i = 0; i < count; i++)
	{
		// i��° ���� ���� ���� �ĺ���� ����
		int best = i;

		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã�Ƴ�����
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// ���� ���� �ĺ��� ��ü�ϴ� ���� 
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[])
{
	// TODO : �������� 1~45 ������ ���� 6���� ����ּ���!

	int count = 0;
	while (count != 6)
	{
		int RandValue = 1 + (rand() % 45);

		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == RandValue)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = RandValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	srand((unsigned)time(0));

	// 1) Swap �Լ� �����

	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	cout << a << " : " << b << endl;

	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };

	int size1 = sizeof(numbers); // 6 * 4 = 24
	int size2 = sizeof(int); // 4

	Sort(numbers, sizeof(numbers) / sizeof(int));
	for (int i = 0; i < 6; i++)
		cout << numbers[i] << " ";
	cout << endl;

	// 3) �ζ� ������
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << " ";
	}

	return 0;
}