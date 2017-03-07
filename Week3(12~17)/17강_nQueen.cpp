#include <stdio.h>
#define CHECK (1)
#define MAX_CNT 15

int columnChk[MAX_CNT+1];             // column 체크 배열 (0번방 사용 안함)
int incDiagonalLineChk[MAX_CNT*2+1];  // 각도가 증가하는 대각선 체크 배열 (0번방 사용 안함)
int decDiagonalLineChk[MAX_CNT*2+1];  // 각도가 감소하는 대각선 체크 배열 (0번방 사용 안함)
int placementCnt;                     // 서로 공격못하게 배치 가능한 경우의 수 카운트 변수
int n;                                // queen의 수(또한 행,열의 수) 저장변수
/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
void nQueen(int row);

int main()
{
	while(1)  // 퀸의 개수가 1~MAX_CNT 개 범위가 아니면 재입력
	{
		printf("퀸의 개수를 입력 하시오 : ");
		scanf("%d", &n);
		if(n>0 && n<=MAX_CNT)
			break;
	}
	nQueen(1);
	printf("배치 가능한 경우의 수 : %d\n\n", placementCnt);
	getchar(); getchar();
	return 0;
}
/*------------------------------------------------------------------
Function name 	: nQueen() - n개의 queen을 배치하기 위한 재귀호출 함수
Parameters		: row - 체스판의 행번호(0행은 사용 안함)
Returns			: 없음
------------------------------------------------------------------*/
void nQueen(int row)
{
	// TODO
	return;
}
