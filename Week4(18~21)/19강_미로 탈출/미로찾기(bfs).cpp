#include<stdio.h>
#include "circularQueue.h"
#define NL printf("\n")
#define MAX_SIZE 100  /* 미로 row, column의 최대 크기 */

int map[MAX_SIZE + 1][MAX_SIZE  + 1];  /* 미로 지도를 저장할 배열(0행, 0열 사용 안함) */
int row, col;     /* map의 가로(row), 세로(column)의 크기 저장 변수 */
RC  start, goal;  /* 미로의 시작좌표, 골인좌표 저장 */

BOOL dataLoad(const char *fileName); /*  데이터 파일에서 검사할 데이터를 입력 받아 map에 저장하는 함수 */
int solve(); /* 너비 우선탐색(BFS)방식으로 최단거리 구하는 함수 */
void output(); /* 미로 상태 출력함수 */
BOOL inRange(int r, int c); /* row, column의 적합성 판별 함수 */

/*-------------------------------------------------------------------------------------
Function name 	: main()
------------------------------------------------------------------------------------*/
int main()
{
	const char *fileName[] = { "d:\\data\\미로찾기1.txt" , "d:\\data\\미로찾기2.txt",
								"d:\\data\\미로찾기3.txt" };
	size_t i;
	int res;
	for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		if (dataLoad(fileName[i]) == FALSE) return 0;
		res = solve();
		if (res > 0) {
			printf("최단 거리 : %d\n\n", res);
		}
		else {
			printf("도달할 수 없습니다.\n\n");
		}
		
		output();
		NL;
		printf("===================================================================\n\n");
		getchar();
	}
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: dataLoad() - 데이터 파일에서 검사할 데이터를 입력 받아 map에 저장하는 함수
Parameters		: char *fileName - 미로 정보가 저장된 데이터 파일명
Returns			: 파일 읽기가 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL dataLoad(const char *fileName){
	FILE *fp;
	int i,j; /* iterator */
	char ch;
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n"); 	getchar();
		return FALSE;
	}
	if (fscanf(fp, "%d %d\n", &row, &col) != 2) return FALSE;
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			ch = fgetc(fp);   /* fp파일로 부터 한 문자 입력 받음 */
			if (ch == '#') map[i][j] = -1;   /* 입력 받은 문자가 벽 이면 */
			else if (ch == '.') map[i][j] = -2; /* 입력 받은 문자가 길 이면 */
			else if (ch == 'S') {  /* 입력 받은 문자가 시작위치 이면 */
				map[i][j] = 0;
				start.row = i; start.col = j; 
			}
			else if (ch == 'G') {  /* 입력 받은 문자가 도착위치 이면 */
				map[i][j] = -2;    /* goal의 문자를 길(.)로 변경 */
				goal.row = i;	goal.col = j;
			}
		}
		fgetc(fp);  /* 한줄 뒤의 \n(개행문자)를 읽어서 버림 */
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name 	: output() - 미로 상태 출력함수
Parameters		: 없음
Returns			: 없음
--------------------------------------------------------------------------------------*/
void output()
{
	int i, j;
	printf("** 미로출력 **\n");
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			if(map[i][j]==-1)	printf("  #");        
			else if (map[i][j] == -2) printf("  .");  
			else if(map[i][j] == 0) printf("  S");
			else printf("%3d", map[i][j]);
		}
		NL;
	}
	NL;
}
/*--------------------------------------------------------------------------------------
Function name 	: solve() - BFS방식으로 최단거리 구하는 함수
Parameters		: 없음
Returns			: 최단거리 값
--------------------------------------------------------------------------------------*/
int solve()
{
	// TODO
	return 0; // 리턴값은 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name	: inRange() - row, colum의 적합성 판별 함수
Parameters		: int r - 행 값
  	  	  	  	  int c - 열 값
Returns			: 적합한 범위이면 TRUE 리턴, 부적합한 범위이면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL inRange(int r, int c)
{
	if((0<r && r <= row) && (0<c && c <= col))
		return TRUE;
	else
		return FALSE;
}

