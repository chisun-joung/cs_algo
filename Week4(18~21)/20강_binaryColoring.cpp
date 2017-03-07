#include<stdio.h>
#define MAX_VERTEX 200
enum{RED=1, BLUE};
enum BOOL{FALSE, TRUE};

BOOL initGraph(FILE *fp); /* 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 그래프를 초기화하는 함수 */
void solve(int vNum, int col); /* DFS로 탐색하여 coloring이 가능한지 검사 */
void outputGraph(); /* 그래프내의 정점과 간선의 관계를 인접 행렬 형태로 출력 함 */

int graph[MAX_VERTEX][MAX_VERTEX];	/* 정점간의 연결 상태 저장 인접 행렬 배열 */
int color[MAX_VERTEX];	/* 정점의 컬러 값 저장 */
BOOL colorable;			/* binary coloring이 가능하면 TRUE, 아니면 FALSE */
int vertexCnt, edgeCnt;	/* 정점 개수와 간선 개수 저장 공간 */
/*----------------------------------------------------------------------------------------
 함수명 : main()
----------------------------------------------------------------------------------------*/
int main()
{
	int i;
	FILE *fp;			/* 그래프 정보 저장 파일의 파일포인터 */
	fp=fopen("d:\\data\\binaryColor.txt", "rt");
	if(fp==NULL){
		printf("File open error!\n");
		return 1;
	}

	while(initGraph(fp))
	{
		outputGraph();
		for(i=0; i<vertexCnt; ++i)
			color[i] = 0;   /* 정점의 color 정보를 저장할 배열 초기화 */
		colorable=TRUE;		/* binary coloring이 가능으로 초기화 */
		solve(0,RED);  /* 0번 정점, RED color로 깊이우선 탐색 시작 */

		if(colorable == 0)
			printf("Not BinaryColorable.\n\n");
		else
			printf("BinaryColorable.\n\n");
	}
	fclose(fp);
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: initGraph() - 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 그래프를 초기화하는 함수
Parameters		: fp - 그래프 정보를 저장하고 있는 파일의 파일 포인터
Returns			: 그래프 한 세트를 정상적으로 초기화 하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL initGraph(FILE *fp)
{
	int vertex1, vertex2;  /* 간선정보 입력을 위한 공간 */
	int i,j;       /* iterator */

	fscanf(fp, "%d %d\n", &vertexCnt, &edgeCnt);  /* 정점과 간선의 개수를 읽기 */

	if(vertexCnt==0 && edgeCnt==0)
		return FALSE;  /* 그래프 데이터 읽기를 실패하면 false 리턴 */

	/* 정점의 개수에 맞춰 인접 행렬 영역 초기화 */
	for(i=0; i<vertexCnt; ++i)
		for(j=0; j<vertexCnt; ++j)
				graph[i][j] = 0;


	/* 무방향 그래프에서의 대칭성(Symmetry) 고려한 초기화 표기 */
	for(i=0; i<edgeCnt; ++i)
	{
		fscanf(fp, "%d %d\n", &vertex1, &vertex2);
		graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;
	}
	return TRUE;  /* 성공적으로 그래프 데이터를 읽었으면 true 리턴 */
}
/*--------------------------------------------------------------------------------------
Function name 	: outputGraph() - 그래프내의 정점과 간선의 관계를 인접 행렬 형태로 출력 함
Parameters		: 없음
Returns			: 없음
--------------------------------------------------------------------------------------*/
void outputGraph()
{
	int i,j;         /* iterator */

	/* 정점명 가로방향 출력 */
	printf("   ");
	for(i=0; i<vertexCnt; ++i)
		printf("%3d",i);

	printf("\n");

	for(i=0; i<vertexCnt; ++i)
	{
		printf("%3d",  i);
		for(j=0; j<vertexCnt; j++)
				printf("%3d", graph[i][j]);
		printf("\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: solve() - DFS로 탐색하여 coloring이 가능한지 검사
Parameters		: vNum - 정점 번호
             	  col - 지정한 color 값
Returns			: 없음
--------------------------------------------------------------------------------------*/
void solve(int vNum, int col)
{
	// TODO
	return;
}
