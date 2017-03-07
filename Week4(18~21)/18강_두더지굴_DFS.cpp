
#include<stdio.h>
enum BOOL {FALSE, TRUE};
#define NL printf("\n") /* 줄 바꾸기 매크로 */
#define MAX_SIZE 30		/* map의 가로(row), 세로(column)의 최대 크기 */
int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* 두더지 굴의 상태 저장(0행, 0열 사용 안함) */
BOOL dataLoad(const char *fileName);	/* 데이터 파일에서 map정보를 입력 받아 map을 초기화 하는 함수 */
void initTunnelInfo(); 	/* 굴의 정보를 저장할 구조체 배열 초기화 함수 */
void solve(); 			/* 두더지 굴의 개수, 크기를 계산하는 함수(재귀호출 형식의 dfs()함수 이용) */
BOOL inRange(int row, int col);	/* row, column 값의 적합성 판별 함수 */
void dfs(int row, int col, int tNum);	/* row, col의 방이 두더지 굴인지 dfs방식으로 재귀호출하며 검사하는 함수 */
void output();			/* 두더지 굴 정보 출력 함수 */

typedef struct tunnel_info {
	int number;  /* 굴 번호 */
	int size;    /* 굴 크기 */
}TunnelInfo;

TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* 두더지 굴의 크기 저장(2번 방부터 사용) */
int n;  			/* map의 가로(row), 세로(column)의 크기 저장 변수 */
int tunnelNumber;  /* 두더지굴 번호 */
/*-------------------------------------------------------------------------------------
Function name 	: main() - 그래프를 구현하고 DFS 탐색을 실시한다.
------------------------------------------------------------------------------------*/
int main()
{
	const char *fileName[] = { "d:\\data\\두더지굴1.txt" , "d:\\data\\두더지굴2.txt", "d:\\data\\두더지굴3.txt" };
	size_t i;
	for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		tunnelNumber = 2; /* 두더지굴 번호(1은 터널이 있음을 의미하므로 2번 부터 사용) */
		if (dataLoad(fileName[i]) == FALSE) return 0;
		solve();
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
Parameters		: char *fileName - 두더지 굴의 정보가 저장된 데이터 파일명
Returns			: 파일 읽기가 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL dataLoad(const char *fileName)
{
	FILE *fp;

	int i, j; /* iterator */
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n");
		getchar();
		return FALSE;
	}
	if (fscanf(fp, "%d", &n) != 1) return FALSE;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (fscanf(fp, "%d", &map[i][j]) != 1) return FALSE;
		}
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name 	: initTunnelInfo() - 굴의 정보를 저장할 구조체 배열 초기화 함수
Parameters		: 없음
Returns			: 없음
--------------------------------------------------------------------------------------*/
void initTunnelInfo()
{
	int i;
	for (i = 0; i <= MAX_SIZE*2; ++i) {
		tunnelInfo[i].number = i;
		tunnelInfo[i].size = 0;  /* extern으로 선언된 배열의 멤버이므로 안해도 됨 */
	}
}
/*--------------------------------------------------------------------------------------
Function name 	: solve() - 두더지 굴의 개수, 크기를 계산하는 함수(재귀호출 형식의 dfs를 이용한 풀이)
Parameters		: 없음
Parameters		: 없음
--------------------------------------------------------------------------------------*/
void solve()
{
	// TODO
	return;
}
/*--------------------------------------------------------------------------------------
Function name 	: inRange() - row, column의 적합성 판별 함수
Parameters		: int row - 행 값
                  int col - 열 값
Returns			: 적합한 범위이면 TRUE 리턴, 부적합한 범위이면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL inRange(int row, int col)
{
	if((0<row && row<=n) && (0<col && col<=n))
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name 	: dfs() - row, col의 방이 두더지 굴인지 dfs방식으로 재귀호출하며 검사하는 함수
Parameters		: int row - 행 값
				  int col - 열 값
                  int tNum - 두더지 굴 번호
Returns			: 없음
--------------------------------------------------------------------------------------*/
void dfs(int row, int col, int tNum)
{
	// TODO
	return;
}
/*--------------------------------------------------------------------------------------
Function name 	: output() - 두더지 굴 정보 출력함수
Parameters		: 없음
Returns			: 없음
--------------------------------------------------------------------------------------*/
void output()
{
	int i, j;
	printf("** 두더지 굴 개수 : %d개\n", tunnelNumber-2);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			printf("%3d", map[i][j]);
		}
		NL;
	}
	NL;

	printf("** 두더지 굴 정보 출력 **\n");
	for (i = 2; i < tunnelNumber; ++i) {
		printf("size of tunnel %d : %d\n", tunnelInfo[i].number, tunnelInfo[i].size);
	}

}
