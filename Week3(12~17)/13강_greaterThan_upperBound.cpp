#include <stdio.h>
#include <malloc.h>
int greaterThan(int *ap, size_t size, int key); /* key값 보다 큰 수가 처음으로 나타나는 위치를 리턴하는 함수 */
int upperBound(int *ap, size_t size, int key); /* key값 보다 크거나 같은 수가 처음으로 나타나는 위치를 리턴하는 함수 */
void bubbleSort(int *ap, int size); /* 버블 정렬 함수 */
void output(int *ap, size_t size); /* 배열의 모든 원소 출력하기 */
void myflush(); /* 입력버퍼(stdin)안의 모든 데이터를 삭제 함 */
/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main() {
	int ary[] = { 15, 5, 3, 7, 15, 7, 30, 12, 20, 40, 7 };
	size_t size; /* 배열요소 개수 저장 */
	int key; /* 검사할 숫자 저장 */
	int position; /* 위치 저장 */
	int res; /* scanf()함수의 리턴값 저장 */

	size = sizeof(ary) / sizeof(ary[0]); /* 배열의 방의 개수 계산 */
	bubbleSort(ary, size);
	output(ary, size);

	/* upperBound(key값 보다 크거나 같은 수의 첫 위치) 검색 테스트 */
	printf("------------------------------------------------\n");
	printf("  upperBound(key값 보다 크거나 같은수의 첫 위치) 검색 테스트 \n");
	printf("------------------------------------------------\n");
	while (1) {
		printf("검사할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if (res != 1) {
			break;
		} /* 문자입력 시 종료 */
		position = upperBound(ary, size, key);
		printf("%d 보다 크거나 같은 수의 첫 위치는 %d 번째 입니다.\n", key, position);
	}
	myflush(); /* 입력버퍼(stdin)내의 모든 데이터를 삭제 */

	output(ary, size);
	/* greaterThan(key값 보다 큰수의 첫위치) 검색 테스트 */
	printf("------------------------------------------------\n");
	printf("    greaterThan(key값 보다 큰수의 첫위치) 검색 테스트 \n");
	printf("------------------------------------------------\n");
	while (1) {
		printf("검사할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if (res != 1) {
			break;
		} /* 문자입력 시 종료 */
		position = greaterThan(ary, size, key);
		printf("%d 보다 큰수의 첫 위치는 %d 번째 입니다.\n", key, position);
	}
	myflush();
	getchar();
	return 0;
}
/*---------------------------------------------------------------------
 Function name 	: upperBound() - key값 보다 크거나 같은 수가 처음으로 나타나는 위치를 리턴하는 함수
 Parameters		: ap - 검색할 데이터 배열의 시작주소
 	 	 	 	  size - 배열내의 데이터 수
 	 	 	 	  key - 검사할 데이터
 Returns		: key값 보다 크거나 같은 수가 처음으로 나타나는 위치를 리턴
 --------------------------------------------------------------------*/
int upperBound(int *ap, size_t size, int key) {
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*---------------------------------------------------------------------
 Function name 	: greaterThan() - key값 보다 큰 수가 처음으로 나타나는 위치를 리턴하는 함수
 Parameters		: ap - 검색할 데이터 배열의 시작주소
 	 	 	 	  size - 배열내의 데이터 수
 	 	 	 	  key - 검사할 데이터
 Returns		: key값 보다 큰 수가 처음으로 나타나는 위치 리턴
 --------------------------------------------------------------------*/
int greaterThan(int *ap, size_t size, int key) {
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*--------------------------------------------------------------------------------------
 Function name 	: bubbleSort() - 버블 정렬 함수
 Parameters		: ary - 정렬할 데이터 배열의 시작주소
 	 	 	 	  size - 소트할 데이터의 개수
 Returns		: 없음
 --------------------------------------------------------------------------------------*/
void bubbleSort(int *ap, int size) {
	int i, j, temp;
	for (i = size; i > 1; i--) {
		for (j = 1; j < i; j++) {
			if (ap[j - 1] > ap[j]) {
				temp = ap[j - 1];
				ap[j - 1] = ap[j];
				ap[j] = temp;
			}
		}
	}
}
/*------------------------------------------------------------------------
 Function name 	: output() - 배열의 모든 원소 출력하기
 Parameters		: ap - 정렬할 데이터 배열의 시작주소
 	 	 	 	  size - 데이터의 개수
 Returns		: 없음
 ------------------------------------------------------------------------*/
void output(int *ap, size_t size) {
	size_t i;
	printf("순       번 : ");
	for (i = 0; i < size; i++) {
		printf("|%4d", i+1);
	}
	printf("\n배열 데이터 : ");
	for (i = 0; i < size; i++) {
		printf("%5d", ap[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
 Function name 	: myflush() - 입력버퍼(stdin)안의 모든 데이터를 삭제 함
 Parameters		: 없음
 Returns			: 없음
 ------------------------------------------------------------------------*/
void myflush() {
	while (getchar() != '\n') {
		;
	}
}
