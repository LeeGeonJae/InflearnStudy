#include <iostream>

using namespace std;

// 오늘의 주제 : 함수 마무리

// 오버로딩 ( 중복 정의 : 함수 이름 재사용 )
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)
int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}

void SetPlayerInto(int hp, int mp, int attack, int guildId = 1, int castleId = 2)
{

}

// 스택 오버플로우

int Factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * Factorial(n - 1);
}

int main()
{
	int result = Factorial(5);
	cout << result << endl;

	return 0;
}

