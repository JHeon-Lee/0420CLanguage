#include <stdio.h>

/*
	stream --> ����� ������ �ٸ� ���� / �ܹ��� ���� / �ڵ� ����,�Ҹ�

	stdin : ǥ�� �Է� ��Ʈ��
	stdout : ǥ�� ��� ��Ʈ��
	stderr : ǥ�� ���� ��Ʈ��

	���� : ������ ������ ȿ�� up (a,p,p,l,e 5�� ���� -> apple 1�� ����)
	getchar() �� ���
*/

int main()
{
	char words[100];
	char words2[100];

	scanf_s("%s", words, sizeof(words)); // ���ۿ� hello world ����

	printf("%s\n", words); // hello world �Է� -> hello ��� --> ���鹮�ڸ� NULL�� �ν�

	while (getchar() != '\n'); // ������ ���ۿ� �����ִ�((����)world(NULL)) �� �ٷ� ��µ�
	// getchar();

	gets(words2); // C ������ ��� ����
	printf("%s\n", words2); // ���� �����ؼ� ���
	
	return 0;
}