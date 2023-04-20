#define _CRT_SECURE_NO_WARNINGS // strcpy 보안문제 해결
#include <stdio.h>
//#include <string.h> // --> 문자열 사용하기 위한 라이브러리



void string(); // char의 배열

int myStrlen(char str[]);

int main()
{
	string();
	{
		char str[100] = "hello C language";

		printf("strlen : %d\n", strlen(str)); // 문자열의 길이 출력 (NULL 은 포함 안됨)

		char str1[20];
		printf("strcpy : %s\n", strcpy(str1, str)); // 복사

		str[0] = 'z';
		printf("strcmp : %d\n", strcmp(str, str1)); // 비교
		/*str1 < str2 인 경우에는 음수 반환
		str1 > str2 인 경우에는 양수 반환
		str1 == str2 인 경우에는 0을 반환 합니다.*/

		printf("strcat : %s\n", strcat(str, str1)); // 2개 병합

		// ---> homework : string.h 라이브러리 없이 위의 기능을 똑같이 하는 함수 만들기
	}

	return 0;
}

void string()
{
	char var1 = NULL;
	char var2 = 0;
	char var3 = '\0';

	char notNyll = '0'; // 문자 0 --> 위에랑 다름

	{
		char hello[] = { 'H','e','l' ,'l' ,'o' }; // --> 크기가 5로 잡힘

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]);
		printf("\n%s\n", hello); // --> 끝에 쓰레기값 출력 --> 마지막 값을 NULL 로 바꿔야함

		hello[4] = '\0';
		printf("\n%s\n", hello);
	}
	{
		char hello[] = { 'H','e','l' ,'l' ,'o', '\0' };

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]);
		printf("\n%s\n", hello);
	}
	{
		char hello[] = "hello"; // --> 크기가 6으로 잡힘
		printf("\n%s\n", hello);
	}
}

int myStrlen(char str[])
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return len;
}
