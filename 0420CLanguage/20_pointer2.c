#include <stdio.h>

// 배열과 포인터의 관계.

void pointer_arr();
void pointer_operation();
void string_pointer();
void pointer_arr_and_2d_arr();
void pointer_and_const_arr();
void void_pointer();

int main()
{
	// pointer_arr();
	// pointer_operation();
	// string_pointer();
	pointer_arr_and_2d_arr();
	// pointer_and_const_arr();
	// void_pointer();

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

	//int* ptr = &arr1[0];
	int* ptr = arr1; // 윗줄과 동일

	printf("%d %d\n", ptr[0], arr1[0]);
	printf("%d %d\n", ptr[1], arr1[1]);
	printf("%d %d\n", ptr[2], arr1[2]);
	printf("%d %d\n", *ptr, *arr1);

	//int a;
	//scanf_s("%d", &a); 배열의 이름일땐 & 안들어감

	// arr[i] = *(arr + i)
}

void pointer_operation()
{
	int* ptr2 = 0x0010;
	double* ptr3 = 0x0010; // c++에선 불가

	printf("%p\n", ptr2 + 1); // int 4byte 증가
	printf("%p\n\n", ptr3 + 1); // double 8byte 증가
	printf("%p %p\n", ptr2, ptr3);
	ptr2++;
	ptr3++;
	printf("%p %p\n", ptr2, ptr3);

	int arr[3] = { 11,22,33 };
	int* ptr = arr;
	printf("%d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2));


	printf("%d\n", *ptr); ptr++;
	printf("%d\n", *ptr); ptr++;
	printf("%d\n", *ptr); ptr--;
	printf("%d\n", *ptr); ptr--;
	printf("%d\n", *ptr);
}

void string_pointer()
{
	char str[] = "string"; // 변수형태
	str[0] = 'c';
	printf("%s\n", str);

	char* pstr = "PtrString"; // 상수형태
	// pstr[0] = "c"; // 오류남
	// printf("%s\n", pstr);

	char* str1 = "Hello"; // 지정하는 포인터는 변경 가능하지만, 위처럼 인덱스를 사용해 변경하려면 에러남
	printf("%s\n", str1);

	str1 = "bye";
	printf("%s\n", str1);
}

void pointer_arr_and_2d_arr()
{
	float arr[2][4] =
	{
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f}
	};

	printf("&a[0][0] : 0x%p\n", arr); // 배열의 이름 = 첫번째 주소
	printf("&a[0][0] : 0x%p\n", arr[0]); // 0행의 이름
	printf("&a[0][0] : 0x%p\n", &arr); // 배열의 첫 주소
	printf("\n");

	printf("&a[0][0] : 0x%p\n", *arr); // 첫 행의 주소   역참조 한번 ---> 행 표현
	printf("&a[0][0] : 0x%p\n", &arr[0]); // 첫 행의 주소
	printf("&a[0][0] : 0x%p\n", &arr[0][0]); // 첫 행 첫 열의 주소
	printf("\n");

	printf("arr[0][0] : %f, %f\n\n", **arr, arr[0][0]); // 값

	printf("0x%p\n", (arr + 1)); // 1행 0열의 주소값이 나옴
	printf("0x%p\n", (&arr[1])); // 1행의 주소
	printf("0x%p\n", arr[1]); // 1행의 이름 = 1행의 주소
	printf("0x%p\n", *(arr + 1)); // 0 + 1 행의 역참조
	printf("0x%p\n", (&arr[0] + 1)); // 0행의 주소 + 1 (포인터 연산)
	printf("0x%p\n", (&arr[1][0])); // 1행 0열의 주소
	printf("\n");

	printf("%f\n\n", *(*(arr + 1) + 2)); // 1행 2열의 값

	{
		int arr[2][3] =
		{
			{0,1,2},
			{3,4,5}
		};

		int** ptrArr = arr;
		// printf("%d", ptrArr[0][0]); 에러 --> 더블포인터는 참조만 가능
	}

	{
		int arr0[3] = { 10,20,30 };
		int arr1[3] = { 40,50,60 };

		int* ptrArr[2] = { arr0, arr1 }; // 2행 3열의 포인터가 만들어짐

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				printf("%d(== %d, %d) => 0x%p", ptrArr[i][j], *(ptrArr[i] + j), *(*(ptrArr + i)), &ptrArr[i][j]);
			}
			printf("\n");
		}
	}
	{
		int myArr[2][3] = { {1,2,3},{4,5,6} };

		int* ptrArr[3];
		ptrArr[0] = myArr[0];
		ptrArr[1] = myArr[1];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d %d %d %d 0x%p 0x%p\n", myArr[i][j], ptrArr[i][j], *(ptrArr[i] + j), *(*(ptrArr + i) + j), &myArr[i][j], &ptrArr[i][j]);
			}
		}
	}
}

void pointer_and_const_arr()
{
	const double PI = 3.14;
	// double const PI = 3.14; 같음

	const int arr1[5] = { 0,1,2,3,4 };
	// arr1[0] = 5; 에러

	double arr2[3] = { 1.0, 2.0, 3.0 };
	double* ptr1 = arr2;
	*ptr1 = 30.0;
	ptr1[0] = 3.0;

	const double arr3[3] = { 1.0,2.0,3.0 };
	double* ptr2 = arr3;
	// arr3[0] = 5.0; 에러
	*ptr2 = 5.0; // 조작 가능 ---> 포인터에도 상수화가 필요
	printf("%f\n", arr3[0]);

	const double arr4[3] = { 1.0,2.0,3.0 };
	const double* ptr3 = arr4;
	//*ptr3 = 7.0;
	//ptr3[0] = 7.0; --> 둘다 에러

	const double arr5[3] = { 1.0,2.0,3.0 };
	// const double* ptr4 = arr5;
	// ptr4 = arr4; // ----> 조작 가능 그래서..

	double const* const ptr5 = arr5;
	/*ptr5 += 1;
	ptr5++;
	ptr5 = arr4; ---> 모두 불가능*/
}

void void_pointer()
{
	int num = 10;
	int* p = &num;
	void* vp = p;

	printf("p : %p\n", p);
	printf("vp : %p\n\n", vp);

	printf("*p : %d\n", *p);
	// printf("*vp : %d\n", *vp); ---> 에러

	int* p0 = (int*)vp; // 동적할당에 사용
}

// homework 2차원 배열 사용해서
// 5*5 빙고 3줄이면 승리 만들기 
// 달팽이 배열 만들기