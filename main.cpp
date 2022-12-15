#include <iostream>

using namespace std;

// ������ ���� : �Լ� ������

// typedef�� ����
// typedef ���� ������ -> ������ (Ŀ���� Ÿ�� ����)

// ��Ȯ���� ����/������ ������ �ƴ϶�
// [���� ����]���� typedef�� �տ��� ���̴� ��
class Knight;

typedef int INTEGER;
typedef int* POINTER;
typedef int FUNC(int, int);
typedef int ARRAY[20];
typedef int (*PFUNC)(int, int); // �Լ� ������
typedef int(Knight::*PMEMFUNC)(int, int); // ��� �Լ� ������

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int t(int a, int b)
{
	cout << "t" << endl;
	return a + b;
}

class Knight
{
public:

	// ��� �Լ�
	int GetHP(int, int)
	{
		cout << "GetHP()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};

int main()
{
	// �Լ� ������
	// 1) ������			*
	// 2) ���� �̸�		fn
	// 3) ������ Ÿ��		�Լ� (���ڴ� int, int ��ȯ�� int)
	//int (*fn)(int, int);


	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;
	PFUNC fn;
	
	fn = &Test; // & ���� ���� (c��� ȣȯ�� ����)

	fn(1, 2);
	(*fn)(1, 2);

	// �� �������� [���� �Լ� / ���� �Լ�]�� ���� �� �ִ� (ȣ�� �Ծ��� ������ �ֵ�)
	//fn = &Knight::GetHP;

	Test(1,2);

	Knight k1;
	k1.GetHP(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHP;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}