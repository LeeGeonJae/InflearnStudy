#include <iostream>

using namespace std;

// 오늘의 주제 : 연습문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int count = 0;

	while (str[count] != '\0')
		count++;

	return count;
}

// 문제2) 문자열 복사 함수
// [H][e][l][l][o]['\0'][][][][][][][][][][][]
// [H][e][l][l][o]['\0'][][][][][][][][][][][]

// src [ 주소 ]
char* StrCpy(char* dest, char* src)
{
	int i = 0;
	//for (i = 0; i <= StrLen(src); i++)
	//{
	//	dest[i] = src[i];
	//}

	//while (src[i] != '\0')
	//{
	//	dest[i] = src[i];
	//	i++;
	//}

	//dest[i] = '\0';

	//return dest;

	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

// 문제 3) 문자열 덧붙이는 함수
// [H][e][l][l][o]['\0'][][][][][][][][][][][]
// [W][o][r][l][d]['\0'][][][][][][][][][][][]
char* StrCat(char* dest, char* src)
{
	// 배열을 이용한 코드
	//int i = 0;
	//int len = StrLen(dest);
	//while (src[i] != '\0')
	//{
	//	dest[i + len] = src[i];
	//	i++;
	//}

	//dest[len + i] = '\0';
	//return dest;

	// 포인터를 이용한 코드
	char* ret = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return ret;
}


// 문제 4) 두 문자열을 비교하는 함수
int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i] < b[i])
		{
			return -1;
		}
		i++;
	}

	return 0;
}

// 문제 5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	// 2
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][][][][][][][]
	char a[BUF_SIZE] = "Hello World";
	char b[BUF_SIZE] = "Hello";

	// 문제 1번 출력 - strlen(a) 문자열 a의 길이
	//int len = StrLen(a);
	//cout << len << endl;

	// 문제 2번 출력 - strcpy(b, a) 문자열 b에 a를 복사
	//StrCpy(b, a);
	//for (int i = 0; i <= StrLen(b); i++)
	//	cout << b[i];

	// 문제 3번 출력 - strcat(a, b) 문자열 a의 뒤에 문자열 b를 복사
	//StrCat(a, b);
	//for (int i = 0; i <= StrLen(a); i++)
	//	cout << a[i];

	// 문제 4번 출력 - a가 더 크면 1, b가 더 크면 -1, 둘다 같으면 0
	//int value = StrCmp(a, b);
	//cout << value << endl;

	// 문제 5번 출력 - a의 문자열 뒤집기
	ReverseStr(a);
	for (int i = 0; i <= strlen(a); i++)
		cout << a[i];

	return 0;
}