#include <iostream>
using namespace std;

// ������ ���� : ����

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

void PrintInfobyCopy(StatInfo info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

void PrintInfobyPtr(StatInfo* info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;
}

void PrintInfobyRef(StatInfo& info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

// Statinfo ����ü�� 1000����Ʈ¥�� ���� ����ü���?
// - (�� ����) Statinfo�� �ѱ�� 1000����Ʈ�� ����Ǵ�
// - (�ּ� ����) Statinfo*�� 8����Ʈ
// - (���� ����) Statinfo&�� 8����Ʈ

// 3) ���� ���� ���
// �� ����ó�� ���ϰ� ����ϰ�!
// �ּ� ����ó�� �ּҰ��� �̿��� ������ �ǵ帮�� ���

int main()
{
	// 4����Ʈ ������ �ٱ��ϸ� ����Ҳ���.
	// ������ �� �ٱ��� �̸��� number��� �Ұ�.
	// �׷��ϱ� number���� �� �����ų�, number�� �� �ִ´ٰ� �ϸ�
	// �������� �˾Ƶ�� �ش� �ּ�(data, stack, heap)�� 1�� �־��ָ� �ȴ�!
	int number = 1;

	// * �ּҸ� ��� �ٱ���
	// int �� �ٱ��ϸ� ���󰡸� int ������(�ٱ���)�� ����
	int* pointer = &number;
	// pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�.
	*pointer = 2;

	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
	// ������ ����ϴ� ����� int*�� �ƴ� int�� ����.
	// 
	int& reference = number;

	// C++���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
	// number��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٰ�~~
	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������,
	// ���� number �ٱ���(�������ٰ�) �� ���� �����ų� ������ ��!
	reference = 3;

	// �׷��� ������ �� �ٸ� �̸��� ���� ������?
	// �׳� number = 3; �̶�� �ص� �Ȱ���.
	// ���� ���� ������ ū ������ �ִ�!

	StatInfo info;
	CreateMonster(&info);

	PrintInfobyCopy(info);
	PrintInfobyPtr(&info);
	PrintInfobyRef(info);

	return 0;
}