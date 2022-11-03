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
	// 가위바위보 상수로 지정
	const int ROCK = 1;
	const int SCISSOR = 2;
	const int PAPER = 3;

	// 승리와 합계 변수로 지정
	int Wins = 0;
	int Total = 0;

	// 게임이 꺼지지 않고 지속적으로 할 수 있게 true 값으로 계속
	while (true)
	{
		// 시드 설정
		srand(time(0));

		// 내가 가위바위보를 낸 값과 컴퓨터가 랜덤으로 낸 값
		int input;
		int ComputerValue = 1 + (rand() % 3);

		// 승률
		if (Total == 0)
		{
			cout << "현재 승률은 없습니다." << endl;
		}
		else
		{
			cout << "현재 승률은" << (Wins * 100) / Total << "% 입니다." << endl;
		}

		// 가위바위보 물어보기
		// 그 값을 input으로 받기
		cout << "무엇을 내시겠습니까? 바위(1), 가위(2), 보(3)" << endl;
		cout << ">";
		cin >> input;

		// switch 문으로 값을 받고 컴퓨터 랜덤 값과 비교해서 무승부, 승리, 패배
		switch (input)
		{
		case ROCK:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "컴퓨터는 주먹을 냈습니다." << endl;
				cout << "무승부입니다." << endl;
				break;
			case SCISSOR:
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				Total++;
				Wins++;
				break;
			case PAPER:
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				Total++;
				break;
			}
			break;
		case SCISSOR:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "컴퓨터는 주먹을 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				Total++;
				break;
			case SCISSOR:
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "무승부입니다." << endl;
				break;
			case PAPER:
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				Total++;
				Wins++;
				break;
			}
			break;
		case PAPER:
			switch (ComputerValue)
			{
			case ROCK:
				cout << "컴퓨터는 주먹을 냈습니다." << endl;
				cout << "승리하셨습니다." << endl;
				Total++;
				Wins++;
				break;
			case SCISSOR:
				cout << "컴퓨터는 가위를 냈습니다." << endl;
				cout << "패배하셨습니다." << endl;
				Total++;
				break;
			case PAPER:
				cout << "컴퓨터는 보를 냈습니다." << endl;
				cout << "무승부입니다." << endl;
				break;
			}
			break;
		default:
			cout << "뭘 낸겁니까?" << endl;
			break;
		}
	}

	return 0;
}