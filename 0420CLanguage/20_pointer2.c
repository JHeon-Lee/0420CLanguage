#include <stdio.h>

// �迭�� �������� ����.

void pointer_arr();

int main()
{
	pointer_arr();

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

	//int* ptr = &arr[0];
	int* ptr = arr; // ���ٰ� ����

	printf("%d %d\n", ptr[0], arr[0]);
	printf("%d %d\n", ptr[1], arr[1]);
	printf("%d %d\n", ptr[2], arr[2]);
	printf("%d %d\n", *ptr, *arr);

	//int a;
	//scanf_s("%d", &a); �迭�� �̸��϶� & �ȵ�
}
