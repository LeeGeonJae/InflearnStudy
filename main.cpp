#include <iostream>

using namespace std;

// 오늘의 주제 : 로또 번호 생성기

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
		// i번째 값이 가장 좋은 후보라고 가정
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾아나선다
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// 제일 좋은 후보와 교체하는 과정 
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[])
{
	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요!

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

	// 1) Swap 함수 만들기

	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	cout << a << " : " << b << endl;

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };

	int size1 = sizeof(numbers); // 6 * 4 = 24
	int size2 = sizeof(int); // 4

	Sort(numbers, sizeof(numbers) / sizeof(int));
	for (int i = 0; i < 6; i++)
		cout << numbers[i] << " ";
	cout << endl;

	// 3) 로또 생성기
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << " ";
	}

	return 0;
}