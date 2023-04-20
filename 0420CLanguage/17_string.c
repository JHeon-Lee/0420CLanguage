#define _CRT_SECURE_NO_WARNINGS // strcpy ���ȹ��� �ذ�
#include <stdio.h>
//#include <string.h> // --> ���ڿ� ����ϱ� ���� ���̺귯��



void string(); // char�� �迭

int myStrlen(char str[]);

int main()
{
	string();
	{
		char str[100] = "hello C language";

		printf("strlen : %d\n", strlen(str)); // ���ڿ��� ���� ��� (NULL �� ���� �ȵ�)

		char str1[20];
		printf("strcpy : %s\n", strcpy(str1, str)); // ����

		str[0] = 'z';
		printf("strcmp : %d\n", strcmp(str, str1)); // ��
		/*str1 < str2 �� ��쿡�� ���� ��ȯ
		str1 > str2 �� ��쿡�� ��� ��ȯ
		str1 == str2 �� ��쿡�� 0�� ��ȯ �մϴ�.*/

		printf("strcat : %s\n", strcat(str, str1)); // 2�� ����

		// ---> homework : string.h ���̺귯�� ���� ���� ����� �Ȱ��� �ϴ� �Լ� �����
	}

	return 0;
}

void string()
{
	char var1 = NULL;
	char var2 = 0;
	char var3 = '\0';

	char notNyll = '0'; // ���� 0 --> ������ �ٸ�

	{
		char hello[] = { 'H','e','l' ,'l' ,'o' }; // --> ũ�Ⱑ 5�� ����

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]);
		printf("\n%s\n", hello); // --> ���� �����Ⱚ ��� --> ������ ���� NULL �� �ٲ����

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
		char hello[] = "hello"; // --> ũ�Ⱑ 6���� ����
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
