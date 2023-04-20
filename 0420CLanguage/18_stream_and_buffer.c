#include <stdio.h>

/*
	stream --> 입출력 사이의 다리 역할 / 단방향 전송 / 자동 생성,소멸

	stdin : 표준 입력 스트림
	stdout : 표준 출력 스트림
	stderr : 표준 에러 스트림

	버퍼 : 데이터 전송의 효율 up (a,p,p,l,e 5번 전송 -> apple 1번 전송)
	getchar() 로 비움
*/

int main()
{
	char words[100];
	char words2[100];

	scanf_s("%s", words, sizeof(words)); // 버퍼엔 hello world 저장

	printf("%s\n", words); // hello world 입력 -> hello 출력 --> 공백문자를 NULL로 인식

	while (getchar() != '\n'); // 없으면 버퍼에 남아있는((띄어쓰기)world(NULL)) 가 바로 출력됨
	// getchar();

	gets(words2); // C 에서만 사용 가능
	printf("%s\n", words2); // 공백 포함해서 출력
	
	return 0;
}