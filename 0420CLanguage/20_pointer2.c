#include <stdio.h>

// �迭�� �������� ����.

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

	printf("�迭�� �̸� : %p\n", arr);
	printf("ù��° ��� : %p\n", &arr[0]); // �迭�� �̸��� ����
	printf("�ι�° ��� : %p\n", &arr[1]);
	printf("����° ��� : %p\n", &arr[2]);

	// arr = &arr[1]; ������ ������̵Ǽ� ����

	/*
		������ ���� vs �迭�� �̸�
		�̸� ����, ��ȯ�ϴ� �� ����. ��, �����ͺ����� ���� ����, �迭�� �̸��� ���� �Ұ�
	*/

	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1,2.2,3.3 };

	printf("%d %g\n", *arr1, *arr2);

	*arr1 += 100;
	*arr2 += 120.4;

	printf("%d %g\n", *arr1, *arr2);
	printf("%d %g\n", arr1[0], arr2[0]);

	//int* ptr = &arr1[0];
	int* ptr = arr1; // ���ٰ� ����

	printf("%d %d\n", ptr[0], arr1[0]);
	printf("%d %d\n", ptr[1], arr1[1]);
	printf("%d %d\n", ptr[2], arr1[2]);
	printf("%d %d\n", *ptr, *arr1);

	//int a;
	//scanf_s("%d", &a); �迭�� �̸��϶� & �ȵ�

	// arr[i] = *(arr + i)
}

void pointer_operation()
{
	int* ptr2 = 0x0010;
	double* ptr3 = 0x0010; // c++���� �Ұ�

	printf("%p\n", ptr2 + 1); // int 4byte ����
	printf("%p\n\n", ptr3 + 1); // double 8byte ����
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
	char str[] = "string"; // ��������
	str[0] = 'c';
	printf("%s\n", str);

	char* pstr = "PtrString"; // �������
	// pstr[0] = "c"; // ������
	// printf("%s\n", pstr);

	char* str1 = "Hello"; // �����ϴ� �����ʹ� ���� ����������, ��ó�� �ε����� ����� �����Ϸ��� ������
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

	printf("&a[0][0] : 0x%p\n", arr); // �迭�� �̸� = ù��° �ּ�
	printf("&a[0][0] : 0x%p\n", arr[0]); // 0���� �̸�
	printf("&a[0][0] : 0x%p\n", &arr); // �迭�� ù �ּ�
	printf("\n");

	printf("&a[0][0] : 0x%p\n", *arr); // ù ���� �ּ�   ������ �ѹ� ---> �� ǥ��
	printf("&a[0][0] : 0x%p\n", &arr[0]); // ù ���� �ּ�
	printf("&a[0][0] : 0x%p\n", &arr[0][0]); // ù �� ù ���� �ּ�
	printf("\n");

	printf("arr[0][0] : %f, %f\n\n", **arr, arr[0][0]); // ��

	printf("0x%p\n", (arr + 1)); // 1�� 0���� �ּҰ��� ����
	printf("0x%p\n", (&arr[1])); // 1���� �ּ�
	printf("0x%p\n", arr[1]); // 1���� �̸� = 1���� �ּ�
	printf("0x%p\n", *(arr + 1)); // 0 + 1 ���� ������
	printf("0x%p\n", (&arr[0] + 1)); // 0���� �ּ� + 1 (������ ����)
	printf("0x%p\n", (&arr[1][0])); // 1�� 0���� �ּ�
	printf("\n");

	printf("%f\n\n", *(*(arr + 1) + 2)); // 1�� 2���� ��

	{
		int arr[2][3] =
		{
			{0,1,2},
			{3,4,5}
		};

		int** ptrArr = arr;
		// printf("%d", ptrArr[0][0]); ���� --> ���������ʹ� ������ ����
	}

	{
		int arr0[3] = { 10,20,30 };
		int arr1[3] = { 40,50,60 };

		int* ptrArr[2] = { arr0, arr1 }; // 2�� 3���� �����Ͱ� �������

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
	// double const PI = 3.14; ����

	const int arr1[5] = { 0,1,2,3,4 };
	// arr1[0] = 5; ����

	double arr2[3] = { 1.0, 2.0, 3.0 };
	double* ptr1 = arr2;
	*ptr1 = 30.0;
	ptr1[0] = 3.0;

	const double arr3[3] = { 1.0,2.0,3.0 };
	double* ptr2 = arr3;
	// arr3[0] = 5.0; ����
	*ptr2 = 5.0; // ���� ���� ---> �����Ϳ��� ���ȭ�� �ʿ�
	printf("%f\n", arr3[0]);

	const double arr4[3] = { 1.0,2.0,3.0 };
	const double* ptr3 = arr4;
	//*ptr3 = 7.0;
	//ptr3[0] = 7.0; --> �Ѵ� ����

	const double arr5[3] = { 1.0,2.0,3.0 };
	// const double* ptr4 = arr5;
	// ptr4 = arr4; // ----> ���� ���� �׷���..

	double const* const ptr5 = arr5;
	/*ptr5 += 1;
	ptr5++;
	ptr5 = arr4; ---> ��� �Ұ���*/
}

void void_pointer()
{
	int num = 10;
	int* p = &num;
	void* vp = p;

	printf("p : %p\n", p);
	printf("vp : %p\n\n", vp);

	printf("*p : %d\n", *p);
	// printf("*vp : %d\n", *vp); ---> ����

	int* p0 = (int*)vp; // �����Ҵ翡 ���
}

// homework 2���� �迭 ����ؼ�
// 5*5 ���� 3���̸� �¸� ����� 
// ������ �迭 �����