#include <iostream>

using namespace std;

enum Enum_SPR
{
	Enum_ROCK = 1,
	Enum_SCISSOR,
	Enum_PAPER
};

int main()
{
	// ���������� ����� ����
	const int ROCK = 1;
	const int SCISSOR = 2;
	const int PAPER = 3;

	// �¸��� �հ� ������ ����
	int Wins = 0;
	int Total = 0;

	// ������ ������ �ʰ� ���������� �� �� �ְ� true ������ ���
	while (true)
	{
		// �õ� ����
		srand(time(0));

		// ���� ������������ �� ���� ��ǻ�Ͱ� �������� �� ��
		int input;
		int ComputerValue = 1 + (rand() % 3);

		// �·�
		if (Total == 0)
		{
			cout << "���� �·��� �����ϴ�." << endl;
		}
		else
		{
			cout << "���� �·���" << (Wins * 100) / Total << "% �Դϴ�." << endl;
		}

		// ���������� �����
		// �� ���� input���� �ޱ�
		cout << "������ ���ðڽ��ϱ�? ����(1), ����(2), ��(3)" << endl;
		cout << ">";
		cin >> input;

		// switch ������ ���� �ް� ��ǻ�� ���� ���� ���ؼ� ���º�, �¸�, �й�
		switch (input)
		{
		case ROCK:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "��ǻ�ʹ� �ָ��� �½��ϴ�." << endl;
				cout << "���º��Դϴ�." << endl;
				break;
			case SCISSOR:
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				Total++;
				Wins++;
				break;
			case PAPER:
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				Total++;
				break;
			}
			break;
		case SCISSOR:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "��ǻ�ʹ� �ָ��� �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				Total++;
				break;
			case SCISSOR:
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "���º��Դϴ�." << endl;
				break;
			case PAPER:
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				Total++;
				Wins++;
				break;
			}
			break;
		case PAPER:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "��ǻ�ʹ� �ָ��� �½��ϴ�." << endl;
				cout << "�¸��ϼ̽��ϴ�." << endl;
				Total++;
				Wins++;
				break;
			case SCISSOR:
				cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl;
				cout << "�й��ϼ̽��ϴ�." << endl;
				Total++;
				break;
			case PAPER:
				cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl;
				cout << "���º��Դϴ�." << endl;
				break;
			}
			break;
		default:
			cout << "�� ���̴ϱ�?" << endl;
			break;
		}
	}

	return 0;
}