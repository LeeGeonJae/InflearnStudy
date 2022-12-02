#include <iostream>

using namespace std;

// ������ ���� : ��������

// ����1) ���ڿ� ���̸� ����ϴ� �Լ�
int StrLen(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int count = 0;

	while (str[count] != '\0')
		count++;

	return count;
}

// ����2) ���ڿ� ���� �Լ�
// [H][e][l][l][o]['\0'][][][][][][][][][][][]
// [H][e][l][l][o]['\0'][][][][][][][][][][][]

// src [ �ּ� ]
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

// ���� 3) ���ڿ� �����̴� �Լ�
// [H][e][l][l][o]['\0'][][][][][][][][][][][]
// [W][o][r][l][d]['\0'][][][][][][][][][][][]
char* StrCat(char* dest, char* src)
{
	// �迭�� �̿��� �ڵ�
	//int i = 0;
	//int len = StrLen(dest);
	//while (src[i] != '\0')
	//{
	//	dest[i + len] = src[i];
	//	i++;
	//}

	//dest[len + i] = '\0';
	//return dest;

	// �����͸� �̿��� �ڵ�
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


// ���� 4) �� ���ڿ��� ���ϴ� �Լ�
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

// ���� 5) ���ڿ��� ������ �Լ�
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

	// ���� 1�� ��� - strlen(a) ���ڿ� a�� ����
	//int len = StrLen(a);
	//cout << len << endl;

	// ���� 2�� ��� - strcpy(b, a) ���ڿ� b�� a�� ����
	//StrCpy(b, a);
	//for (int i = 0; i <= StrLen(b); i++)
	//	cout << b[i];

	// ���� 3�� ��� - strcat(a, b) ���ڿ� a�� �ڿ� ���ڿ� b�� ����
	//StrCat(a, b);
	//for (int i = 0; i <= StrLen(a); i++)
	//	cout << a[i];

	// ���� 4�� ��� - a�� �� ũ�� 1, b�� �� ũ�� -1, �Ѵ� ������ 0
	//int value = StrCmp(a, b);
	//cout << value << endl;

	// ���� 5�� ��� - a�� ���ڿ� ������
	ReverseStr(a);
	for (int i = 0; i <= strlen(a); i++)
		cout << a[i];

	return 0;
}