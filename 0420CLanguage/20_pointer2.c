#include <stdio.h>

// 배열과 포인터의 관계.

void pointer_arr();

int main()
{
	pointer_arr();

	return 0;
}

void pointer_arr()
{
	int arr[3] = { 0,1,2 };

	printf("배열의 이름 : %p\n", arr);
	printf("첫번째 요소 : %p\n", &arr[0]); // 배열의 이름과 동일
	printf("두번째 요소 : %p\n", &arr[1]);
	printf("세번째 요소 : %p\n", &arr[2]);

	// arr = &arr[1]; 왼쪽이 상수값이되서 에러

	/*
		포인터 변수 vs 배열의 이름
		이름 동일, 반환하는 값 동일. 단, 포인터변수는 변경 가능, 배열의 이름은 변경 불가
	*/

	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1,2.2,3.3 };

	printf("%d %g\n", *arr1, *arr2);

	*arr1 += 100;
	*arr2 += 120.4;

	printf("%d %g\n", *arr1, *arr2);
	printf("%d %g\n", arr1[0], arr2[0]);

	//int* ptr = &arr[0];
	int* ptr = arr; // 윗줄과 동일

	printf("%d %d\n", ptr[0], arr[0]);
	printf("%d %d\n", ptr[1], arr[1]);
	printf("%d %d\n", ptr[2], arr[2]);
	printf("%d %d\n", *ptr, *arr);

	//int a;
	//scanf_s("%d", &a); 배열의 이름일땐 & 안들어감
}
