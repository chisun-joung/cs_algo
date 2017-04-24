
#include<stdio.h>
#include<malloc.h>
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
void solve_bfs();
void bfs(int row, int col, int tNum);

typedef struct tunnel_info {
	int number;  /* 굴 번호 */
	int size;    /* 굴 크기 */
}TunnelInfo;

typedef struct rowcol { /* 행열 좌표 1 세트를 저장하는 구조체 */
	int row;
	int col;
}RC;

typedef struct _queue {
	RC *queue;
	int size;
	int front, rear;
} Queue;



TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* 두더지 굴의 크기 저장(2번 방부터 사용) */
int n;  			/* map의 가로(row), 세로(column)의 크기 저장 변수 */
int tunnelNumber;  /* 두더지굴 번호 */

BOOL createQueue(Queue* qp, int size)
{
	if(qp == NULL){
		return FALSE;
	}
	qp->queue = (RC *)calloc(size,sizeof(RC));

	if(qp->queue != NULL) {
		qp->size = size;
		qp->front = 0;
		qp->rear = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}

	if (qp->front == qp->rear)	/* queue가 텅비어 있으면 */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - 큐가 꽉차있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns			: 꽉차 있으면 TRUE 리턴, 아니면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}

	if (qp->front == (qp->rear + 1) % qp->size) /* queue가 완전히 비어 있으면 */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - 큐에 데이터 하나를 저장함
Parameters		: qp - 큐 구조체의 주소
			  	  enqueData - 큐에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, RC enqueData)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}

	if (isQueueFull(qp))	/* queue가 꽉차있으면 enqueue 불가 */
	{
		return FALSE;
	}

	/* rear 위치에 데이터 저장 후 rear 증가 */
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return TRUE;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - 큐에서 데이터 하나를 꺼냄
Parameters		: qp - 큐 구조체의 주소
				  dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, RC * dequeData)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}

	if (isQueueEmpty(qp))	/* 큐가 비어있으면 dequeue 불가 */
	{
		return FALSE;
	}

	/* 데이터를 front위치에서 꺼내 dequeData가 가리키는 곳에 저장 함 */
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - 큐 내의 모든 데이터를 출력 함
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}
	/* queue내의 모든 데이터 출력 (dequeue 하면 출력되는 순서로 출력) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("(%d,%d) ", qp->queue[i].row, qp->queue[i].col);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - 큐 소멸 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}

	if (qp->queue != NULL) { /* queue로 사용되는 배열 메모리 해제 */
		free(qp->queue);
	}
	qp->queue = NULL;	/* queue 멤버를 NULL pointer로 초기화 */
	qp->size = 0;		/* size멤버를 0으로 초기화 */
	qp->front = qp->rear = 0;	/* front, rear 멤버를 0으로 초기화 */
}
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
		solve_bfs();
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
	int i, j;
	initTunnelInfo(); /* 굴의 정보를 저장할 구조체 배열 초기화 */
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* 터널이 발견되면 */
				dfs(i, j, tunnelNumber);  /* 깊이 우선탐색 시작 */
				++tunnelNumber;  /* 두더지 굴 번호(tunnelNumber)를 증가시킴 */
			}
		}
	}
	return;
}

void solve_bfs()
{
	int i, j;
	initTunnelInfo(); /* 굴의 정보를 저장할 구조체 배열 초기화 */
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* 터널이 발견되면 */
				bfs(i, j, tunnelNumber);  /* 너비 우선탐색 시작 */
				++tunnelNumber;  /* 두더지 굴 번호(tunnelNumber)를 증가시킴 */
			}
		}
	}

	return;
}
void bfs(int row, int col, int tNum)
{
	Queue que;
	RC rc,start,tRC;
	RC rcxy[4] ={ {-1,0},{1,0},{0,-1},{0,1}};
	int tY, tX;
	createQueue(&que,MAX_SIZE);
	start.row = row;
	start.col = col;
	enqueue(&que,start);
	while(!isQueueEmpty(&que)) {
		dequeue(&que,&rc);

		for(int i = 0; i< 4; i++) {
			tY = rc.row + rcxy[i].row;
			tX = rc.col + rcxy[i].col;
			if (inRange(tY, tX) && map[tY][tX] == 1) {
						map[tY][tX] = tNum; 		/*  map의 row행 col방의 값을 두더지 굴 번호로 수정 */
						++tunnelInfo[tNum].size;  	/* 두더지굴의 크기 증가 */
						  tRC.row = tY;
						  tRC.col = tX;
						  enqueue(&que,tRC);
			}
		}


	}
	destroyQueue(&que);

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
	if (inRange(row, col) == FALSE) return;
	if (map[row][col] != 1) return;
	map[row][col] = tNum; 		/*  map의 row행 col방의 값을 두더지 굴 번호로 수정 */
	++tunnelInfo[tNum].size;  	/* 두더지굴의 크기 증가 */
	dfs(row - 1, col, tNum);
	dfs(row + 1, col, tNum);
	dfs(row, col - 1, tNum);
	dfs(row, col + 1, tNum);
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
