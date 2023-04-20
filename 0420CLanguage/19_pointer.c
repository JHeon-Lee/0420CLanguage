#include <stdio.h>

// pointer : 주소!
// 주소 크기 : 64bit - 8byte, 32bit - 4byte

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

	//int* pnum1 = &5 --> 상수에 주소값 부여 불가

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

	int* ptr; // 초기화 안되면 쓰레기값 들어감 --> 초기화 반드시 필요
	int* ptr = NULL;
	return 0;
}