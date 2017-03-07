#include <stdio.h>
size_t initArray(int *ap, size_t size); /* 100개 이하로 원하는 만큼 정수를 입력 받아 배열에 저장하는 함수 */
int checkMAX(int *ap, size_t count, size_t *index); /* 배열내의 최대값과 그 위치를 구하는 함수 */
int checkMIN(int *ap, size_t count, size_t *index); /* 배열내의 최소값과 그 위치를 구하는 함수 */
void output(int maxNum, int maxIndex, int minNum, int minIndex); /* 결과 출력 함수 */
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	int ary[100]; /* 최대 최소값을 검사할 데이터를 저장하는 배열 */
	size_t count; /* 배열내에 저장된 데이터의 개수 저장 */
	int maxNum;  /* 최대값 저장 */
	int minNum;  /* 최소값 저장  */
	size_t maxIndex;  /* 최대값의 위치(index) 저장  */
	size_t minIndex;  /* 최소값의 위치(index) 저장  */

	count = initArray(ary, sizeof(ary)/sizeof(ary[0]));
	maxNum = checkMAX(ary, count, &maxIndex);
	minNum = checkMIN(ary, count, &minIndex);
	output(maxNum,maxIndex,minNum,minIndex);

	getchar(); getchar();
	return 0;
}

/*------------------------------------------------------------------
Function name 	: initArray() - 100개 이하로 원하는 만큼 정수를 입력 받아 배열에 저장하는 함수
Parameters		: ap - 데이터 저장배열의 주소
				  size - 배열의 방의 개수
Returns			: 배열내에 저장되어있는 데이터의 개수
------------------------------------------------------------------*/
size_t initArray(int *ap, size_t size)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*------------------------------------------------------------------
Function name 	: checkMAX() - 배열내의 최대값과 그 위치를 구하는 함수
Parameters		: ap - 데이터 저장배열의 주소
				  count - 배열내에 저장되어있는 데이터의 개수
				  index - 최대값의 인덱스를 저장할 변수의 시작주소를 받은 포인터 변수
Returns			: 배열내의 최대값
------------------------------------------------------------------*/
int checkMAX(int *ap, size_t count, size_t *index)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*------------------------------------------------------------------
Function name 	: checkMin() - 배열내의 최소값과 그 위치를 구하는 함수
Parameters		: ap - 데이터 저장배열의 주소
				  count - 배열내에 저장되어있는 데이터의 개수
				  index - 최소값의 인덱스를 저장할 변수의 시작주소를 받은 포인터 변수
Returns			: 배열내의 최소값
------------------------------------------------------------------*/
int checkMIN(int *ap, size_t count, size_t *index)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*------------------------------------------------------------------
Function name 	: output() - 결과 출력 함수
Parameters		: maxNum - 최대값
				  maxIndex - 최대값의 인덱스
				  minNum - 최소값
				  minIndex - 최소값의 인덱스
Returns			: 없음
------------------------------------------------------------------*/
void output(int maxNum, int maxIndex, int minNum, int minIndex)
{
	printf(" 최대값 : %d(index:%d) / 최대값 : %d(index:%d)\n",
			maxNum, maxIndex, minNum, minIndex);
}
