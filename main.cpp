#include <iostream>

using namespace std;

// ������ ���� : �Լ� ������

// �����ε� ( �ߺ� ���� : �Լ� �̸� ���� )
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)
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

// ���� �����÷ο�

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

