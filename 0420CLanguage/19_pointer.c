#include <stdio.h>

// pointer : �ּ�!
// �ּ� ũ�� : 64bit - 8byte, 32bit - 4byte

int main()
{
	char c = 'A';
	int n = 7;
	float f = 3.0f;

	int num = 7;
	int* pnum;
	pnum = &num;
	printf("%d\n", num);

	*pnum = 10;
	printf("%d\n", num);

	//int* pnum1 = &5 --> ����� �ּҰ� �ο� �Ұ�

	printf("%p\n", pnum);
	printf("%d\n", *pnum);
	printf("%d\n", num);
	printf("%p\n", &num);
	printf("%p\n", &pnum);
	printf("%d\n", (int)sizeof(pnum));

	int num2 = 7;
	pnum = &num2;

	printf("%p\n", pnum);
	printf("%p\n", &num2);

	int* ptr; // �ʱ�ȭ �ȵǸ� �����Ⱚ �� --> �ʱ�ȭ �ݵ�� �ʿ�
	int* ptr = NULL;
	return 0;
}