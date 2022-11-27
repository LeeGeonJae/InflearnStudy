#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

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

// Statinfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) Statinfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) Statinfo*는 8바이트
// - (참조 전달) Statinfo&는 8바이트

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 원본을 건드리는 방식

int main()
{
	// 4바이트 정수형 바구니를 사용할꺼야.
	// 앞으로 그 바구니 이름을 number라고 할게.
	// 그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면
	// 찰떡같이 알아듣고 해당 주소(data, stack, heap)에 1을 넣어주면 된다!
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터(바구니)가 있음
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다.
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 하지만 사용하는 방식은 int*가 아닌 int와 같다.
	// 
	int& reference = number;

	// C++관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어줄게~~
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(원본에다가) 그 값을 꺼내거나 넣으면 됨!
	reference = 3;

	// 그런데 귀찮게 또 다른 이름을 짓는 이유는?
	// 그냥 number = 3; 이라고 해도 똑같다.
	// 참조 전달 때문에 큰 장점이 있다!

	StatInfo info;
	CreateMonster(&info);

	PrintInfobyCopy(info);
	PrintInfobyPtr(&info);
	PrintInfobyRef(info);

	return 0;
}