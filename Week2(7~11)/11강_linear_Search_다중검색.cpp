#include <stdio.h>
#include <malloc.h>
int linearUniqueSearch(int *ap, size_t size, int key);	/* 순차검색함수(단일검색) */
size_t *linearMultiSearch(int *ap, size_t size, int key, size_t *pcnt);	/* 순차검색함수(다중검색) */
void output(int *ap, size_t size);	/* 배열의 모든 원소 출력하기 */
void myflush();	/* 입력버퍼(stdin)안의 모든 데이터를 삭제 함 */
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	int ary[]={6,17,3,25,6,17,10,13,35,8,17};
	size_t size;		/* 배열요소 개수 저장 */
	int key;			/* 검색할 숫자 저장 */
	int index;			/* 단일검색된 데이터의 인덱스 저장 */
	size_t i;			/* iterator */
	int res;        	/* scanf()함수의 리턴값 저장 */
	size_t *multiIndex;	/* 다중검색된 데이터의 인덱스 저장 배열의 주소 저장 */
	size_t findCnt;		/* 다중검색된 데이터의 개수 */

	size = sizeof(ary)/sizeof(ary[0]);	/* 배열의 방의 개수 계산 */
	output(ary, size);
	/* 단일 검색 테스트 */
	printf("------------------------------------------\n");
	printf("\t 단일 검색 테스트\n");
	printf("------------------------------------------\n");
	while(1){
		printf("단일 검색할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if(res != 1) {break;}   /* 문자입력 시 종료 */
		if( ( index = linearUniqueSearch(ary, size, key) ) != -1){
			printf("%d는 %d번방 데이터입니다.\n", key, index);
		}
		else{
			printf("%d는 존재하지 않습니다.\n", key);
		}
	}
	myflush();	/* 입력버퍼(stdin)내의 모든 데이터를 삭제 */

	/* 다중 검색 테스트 */
	printf("------------------------------------------\n");
	printf("\t 다중 검색 테스트 \n");
	printf("------------------------------------------\n");
	while(1){
		printf("다중 검색할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if(res != 1) {break;}   // 문자입력 시 종료
		if( ( multiIndex = linearMultiSearch(ary, size, key, &findCnt) ) != NULL){
			printf("%d는 : ", key);
			for(i=0; i<findCnt; ++i){
				printf("%d번방, ", multiIndex[i]);
			}
			printf("\b\b 데이터 입니다.\n");
			free(multiIndex);  /* 안하면 memory leak!! */
		}
		else{
			printf("%d는 존재하지 않습니다.\n", key);
		}
	}
	myflush();
	getchar();
	return 0;
}
/*---------------------------------------------------------------------
Function name 	: linearUniqueSearch() - 순차검색함수(단일검색)
Parameters		: ap - 검색할 데이터 배열의 시작주소
				  size - 배열내의 데이터 수
				  key - 검색할 데이터
Returns			: 검색 성공 시 찾은 숫자의 index 리턴 / 검색 실패 시 -1 리턴
--------------------------------------------------------------------*/
int linearUniqueSearch(int *ap, size_t size, int key)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*---------------------------------------------------------------------
Function name 	: linearMultiSearch() - 순차검색함수(다중검색)
Parameters		: ap - 검색할 데이터 배열의 시작주소
				  size - 배열내의 데이터 개수
				  key - 검색할 데이터
				  pcnt - 검색된 데이터의 개수를 저장한 공간의 시작주소
Returns			: 찾은 index들이 저장된 동적할당 배열의 시작주소 리턴 / 실패 시 NULL pointer 리턴
--------------------------------------------------------------------*/
size_t * linearMultiSearch(int *ap, size_t size, int key, size_t *pcnt)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*------------------------------------------------------------------------
Function name 	: output() - 배열의 모든 원소 출력하기
Parameters		: ap - 정렬할 데이터 배열의 시작주소
				  size - 데이터의 개수
Returns			: 없음
------------------------------------------------------------------------*/
void output(int *ap, size_t size)
{
	size_t i;
	printf("배열 데이터 : ");
	for(i=0; i<size;i++)
	{
		printf(" %d ", ap[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
Function name 	: myflush() - 입력버퍼(stdin)안의 모든 데이터를 삭제 함
Parameters		: 없음
Returns			: 없음
------------------------------------------------------------------------*/
void myflush(){
	while(getchar()!='\n'){
		;
	}
}
