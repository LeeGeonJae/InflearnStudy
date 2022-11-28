#include <iostream>
using namespace std;

// ������ ���� : ���� vs ������

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

StatInfo* FindMonster()
{
	// 1000 : Heap �������� ������ ã�ƺ�
	// ã�Ҵ� !
	// return monster-;

	return nullptr;
}

StatInfo globalInfo;

void PrintInfoByPtr(const StatInfo* const info)
{
	// ���� info�� nullptr�̸� ������ �߻��ϱ� ������ üũ���ش�.
	if (info == nullptr)
		return;
	
	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;

	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!

	// �� ������ ���δٸ�?
	// const StatInfo* info
	// info�� ����Ű�� �ִ� �ٱ����� ���빰�� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲ� �� ����

	// info[ �ּҰ� ]      �ּҰ�[ ������ ]
	// StatInfo* const info �϶� ���� �Ұ�
	// info = &globalInfo;

	// const StatInfo* info �϶� ���� �Ұ�
	// info->hp = 1000;

	// const StatInfo* const info �ϸ� �ּҰ��� �ٱ��� ���� ���빰�� ���ٲٰ� �Ѵ�.
}

void PrintInfoByRef(const StatInfo& info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

#define OUT

void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;

	// ������ vs ����
	// ���� : �Ȱ���
	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� Ī������ �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִµ�
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� �̷� ������� ��ġ�� �κ� ���� ����

	// ����� �����͵� const�� ��� ����
	// * �������� �տ� ���̴��� �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶�����.

	
	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸� (��Ī?)
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� � �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����
	// �����Ϳ��� '����'�� �ǹ̷�? nullptr
	// ���� Ÿ���� �̷� nullptr

	StatInfo* pointer = nullptr;
	int a = NULL;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(reference);

	// �׷��� �����?
	// ��� Team By Team... ������ ���� ����.
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ �����͸� ���
	// ex) �𸮾� �������� reference�� �ֿ�

	// Rookiss ��ȣ ��Ÿ��)
	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null üũ �ʼ�)
	// - �ٲ��� �ʰ� �д� �뵵(readonly)�� ����ϸ� const ref&
	// - �� �� �Ϲ������� ref (�ӽ������� ȣ���� �� OUT�� ���δ�)
	// ������ ���鿡�� OUT�� ���µ� ������ �ƹ� ����� ����.
	// -- �� �ٸ� ����� pointer�� ���������� �̾ ����ٸ�, ��� pointer (���� ������� �ʴ´�)
	ChangeInfo(OUT info);

	// Bonus) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// pointer[ �ּ�(&info) ]  ref. info[ ������ ]
	PrintInfoByRef(*pointer);

	// Bonus) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// pointer[ �ּ� ]  reference. info[ ������ ]
	PrintInfoByPtr(&reference);

	return 0;
}